#include <compiler.h>
#include <atomic.h>
#include <stdio.h>
#include "irda.h"

#define MAX_DATA_FRAMES 84  // IRDA_MAX_PAYLOAD * 8 / 6

static uint8_t tx_buf[MAX_DATA_FRAMES]; // payload to be sent (uart frames; 6 data bits per octet)
static uint8_t tx_len;                  // number of octets in the payload
static uint8_t tx_next;                 // octet to be transmitted next

static bool connected = true;

/**
 * \brief Initialize IrDA USART interface
 * If module is configured to disabled state, the clock to the USART is disabled
 * if this is supported by the device's clock system.
 *
 * \return Initialization status.
 * \retval 0 the USART init was successful
 * \retval 1 the USART init was not successful
 */
int8_t irda_init() {
	int8_t   exp;
	uint32_t div;
	uint32_t limit;
	uint32_t ratio;
	uint32_t min_rate;
	uint32_t max_rate;

	uint32_t cpu_hz = F_CPU;
	uint32_t baud   = 115200;

	/*
	 * Check if the hardware supports the given baud rate
	 */
	/* 8 = (2^0) * 8 * (2^0) = (2^BSCALE_MIN) * 8 * (BSEL_MIN) */
	max_rate = cpu_hz / 8;
	/* 4194304 = (2^7) * 8 * (2^12) = (2^BSCALE_MAX) * 8 * (BSEL_MAX+1) */
	min_rate = cpu_hz / 4194304;

	/* double speed is disabled. */
	max_rate /= 2;
	min_rate /= 2;

	if ((baud > max_rate) || (baud < min_rate)) {
		/* the hardware doesn't supports the given baud rate */
		return -1;
	}

	/* double speed is disabled. */
	baud *= 2;

	/* Find the lowest possible exponent. */
	limit = 0xfffU >> 4;
	ratio = cpu_hz / baud;

	for (exp = -7; exp < 7; exp++) {
		if (ratio < limit) {
			break;
		}

		limit <<= 1;

		if (exp < -3) {
			limit |= 1;
		}
	}

	/*
	 * Depending on the value of exp, scale either the input frequency or
	 * the target baud rate. By always scaling upwards, we never introduce
	 * any additional inaccuracy.
	 *
	 * We are including the final divide-by-8 (aka. right-shift-by-3) in
	 * this operation as it ensures that we never exceeed 2**32 at any
	 * point.
	 *
	 * The formula for calculating BSEL is slightly different when exp is
	 * negative than it is when exp is positive.
	 */
	if (exp < 0) {
		/* We are supposed to subtract 1, then apply BSCALE. We want to
		 * apply BSCALE first, so we need to turn everything inside the
		 * parenthesis into a single fractional expression.
		 */
		cpu_hz -= 8 * baud;

		/* If we end up with a left-shift after taking the final
		 * divide-by-8 into account, do the shift before the divide.
		 * Otherwise, left-shift the denominator instead (effectively
		 * resulting in an overall right shift.)
		 */
		if (exp <= -3) {
			div = ((cpu_hz << (-exp - 3)) + baud / 2) / baud;
		} else {
			baud <<= exp + 3;
			div = (cpu_hz + baud / 2) / baud;
		}
	} else {
		/* We will always do a right shift in this case, but we need to
		 * shift three extra positions because of the divide-by-8.
		 */
		baud <<= exp + 3;
		div = (cpu_hz + baud / 2) / baud - 1;
	}

	USARTD0.BAUDCTRLB = (uint8_t)(((div >> 8) & 0X0F) | (exp << 4));
	USARTD0.BAUDCTRLA = (uint8_t)div;

	USARTD0.CTRLA = USART_RXCINTLVL_MED_gc    /* Medium Level */
	                | USART_TXCINTLVL_OFF_gc  /* Off */
	                | USART_DREINTLVL_MED_gc; /* Medium Level */

	USARTD0.CTRLC = USART_PMODE_DISABLED_gc /* No Parity */
			 | 0 << USART_SBMODE_bp /* Stop Bit Mode: 1 stop bit */
			 | USART_CHSIZE_8BIT_gc /* Character size: 8 bit */
			 | 0 << USART_CHSIZE2_bp /* SPI Master Mode, Data Order: disabled */
			 | 1 << USART_CHSIZE1_bp /* SPI Master Mode, Clock Phase: enabled */
			 | USART_CMODE_IRDA_gc; /* IrDA Mode */

	USARTD0.CTRLB = 0 << USART_CLK2X_bp   /* Double transmission speed: disabled */
	                | 0 << USART_MPCM_bp  /* Multi-processor Communication Mode: disabled */
	                | 1 << USART_RXEN_bp  /* Receiver Enable: enabled */
	                | 1 << USART_TXEN_bp; /* Transmitter Enable: enabled */

	uint8_t x;

    // reset tx/rx packet buffers:
    tx_len = 0;
    tx_next = tx_len;
	return 0;
}

/**
 * \brief Enable RX and TX on IrDA.
 * 1. If supported by the clock system, enables the clock to the USART
 * 2. Enables the USART module by setting the RX and TX enable-bits in the USART control register
 *
 * \return Nothing
 */
void irda_enable() {
	USARTD0.CTRLB |= USART_RXEN_bm | USART_TXEN_bm;
	IRSD_set_level(false);	// enable IrDA
}

/**
 * \brief Enable RX in IrDA.
 * 1. If supported by the clock system, enables the clock to the USART
 * 2. Enables the USART module by setting the RX enable-bit in the USART control register
 *
 * \return Nothing
 */
void irda_enable_rx() {
	USARTD0.CTRLB |= USART_RXEN_bm;
}

/**
 * \brief Enable TX in IrDA.
 * 1. If supported by the clock system, enables the clock to the USART
 * 2. Enables the USART module by setting the TX enable-bit in the USART control register
 *
 * \return Nothing
 */
void irda_enable_tx() {
	USARTD0.CTRLB |= USART_TXEN_bm;
}

/**
 * \brief Disable IrDA.
 * 1. Disables the USART module by clearing the enable-bit(s) in the USART control register
 * 2. If supported by the clock system, disables the clock to the USART
 *
 * \return Nothing
 */
void irda_disable() {
	USARTD0.CTRLB &= ~(USART_RXEN_bm | USART_TXEN_bm);
	IRSD_set_level(true);	// disable IrDA
}

/* Interrupt service routine for RX complete */
ISR(USARTD0_RXC_vect) {
	uint8_t data;
	uint8_t tmphead;

	/* Read the received data */
	data = USARTD0.DATA;
	/* Calculate buffer index */
	tmphead = (USART_1_rx_head + 1) & USART_1_RX_BUFFER_MASK;

	if (tmphead == USART_1_rx_tail) {
		/* ERROR! Receive buffer overflow */
	} else {
		/* Store new index */
		USART_1_rx_head = tmphead;

		/* Store received data in buffer */
		USART_1_rxbuf[tmphead] = data;
		USART_1_rx_elements++;
	}
}

/* Interrupt service routine for Data Register Empty */
ISR(USARTD0_DRE_vect) {
	uint8_t tmptail;

	/* Check if all data is transmitted */
	if (USART_1_tx_elements != 0) {
		/* Calculate buffer index */
		tmptail = (USART_1_tx_tail + 1) & USART_1_TX_BUFFER_MASK;
		/* Store new index */
		USART_1_tx_tail = tmptail;
		/* Start transmission */
		USARTD0.DATA = USART_1_txbuf[tmptail];
		USART_1_tx_elements--;
	}

	if (USART_1_tx_elements == 0) {
		/* Disable UDRE interrupt */
		USARTD0.CTRLA &= ~(USART_DREINTLVL_gm);
	}
}

int8_t send_irda(uint8_t *data, uint8_t len) {
    if (tx_next < tx_len) {
        return ETXBUSY;
    } else if (len > IRDA_MAX_PAYLOAD) {
        return ETXSIZE;
    }

    uint8_t j = 0;
    uint8_t rshift = 2;
    uint8_t lshift;
    for (uint8_t i = 0; i < len; i++) {
        lshift = 6 - rshift;

        tx_buf[j++] = data[i] >> rshift;
        tx_buf[j] = data[i] << lshift;
        
        if (lshift == 0) {
            // we completely filled up the second frame
            j++;
            rshift = 2;
        } else {
            // the send frame was only partially filled
            rshift += 2;
        }
    }
    tx_next = 0;
    tx_len = j + 1;

	/* Enable UDRE interrupt */
	USARTD0.CTRLA |= USART_DREINTLVL_MED_gc;

    return 0;
}
