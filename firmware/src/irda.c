#include <compiler.h>
#include <atomic.h>
#include <stdio.h>
#include <string.h>
#include "alarm.h"
#include "atmel_start_pins.h"
#include "irda.h"
#include "util.h"

enum STATE {
    RX,
    TX
};

static void (*irda_read_callback)(uint8_t *buf, int len) = NULL;

volatile enum STATE state = RX;
void toTx();
void toRx();
void read_timeout();
void enableUDRE();

static volatile uint8_t rx_buf[IRDA_MAXBUF];
static volatile uint8_t tx_buf[IRDA_MAXBUF];
static volatile int rx_pos, tx_pos;
static volatile int tx_len;

bool irda_write_available() {
    return !tx_len;
}

int irda_write(uint8_t *buf, int len) {
    while (tx_len);
    memcpy(tx_buf, buf, min(len, IRDA_MAXBUF));

    DISABLE_INTERRUPTS();
    tx_pos = 0;
    tx_len = min(len, IRDA_MAXBUF);
    ENABLE_INTERRUPTS();
    return 0;
}

ISR(USARTD0_RXC_vect) {
    const uint8_t status = USARTD0.STATUS;
    const bool eof = status & USART_RXB8_bm;
    const uint8_t data = USARTD0.DATA;

//    printf("RXC_vect STATUS=%d data=%d state=%d\r\n", status, data, state);
    if (status & USART_RXCIF_bm) {
        if (eof) {            // end-of-packet frame
            USARTD0.CTRLB &= ~USART_RXEN_bm;            // disable RX
            if (rx_pos && irda_read_callback != NULL) {
                (*irda_read_callback)(rx_buf, rx_pos);  // deliver packet to application
            }

            // We have a half-duplex channel. Give our peer 1ms to transition out of TX
            // mode and enable its receiver and interrupts before we send our first frame.
            set_alarm(1000, toTx);

        } else {
            if (rx_pos >= IRDA_MAXBUF) {
                printf("ERR: IrDA receive overflow\r\n");
            } else {
                rx_buf[rx_pos++] = data;
            }
            set_alarm(1000, read_timeout);
        }
    } else {
        printf("ERR: USARTD0_RXC_vect with USART_RXCIF_bm unset!\r\n");
    }
}

void enableUDRE() {
    USARTD0.CTRLA |= USART_DREINTLVL_MED_gc;    // enable the UDRE interrupt now
}

void toTx() {
    clr_alarm();
    USARTD0.CTRLB &= ~USART_RXEN_bm;            // disable RX

    state = TX;                                 // switch to TX mode
//    printf("INFO: RX -> TX\r\n");

    USARTD0.CTRLA &= ~USART_TXCINTLVL_gm;       // disable TXC interrupt

    enableUDRE();                           // start sending pending frames
//    if (tx_len) {
//    } else {
//        // we have no data to send yet; wait 10ms for a packet to arrive
//        printf("INFO: no data to send yet\r\n");
//        set_alarm(10000, enableUDRE);
//    }
}

ISR(USARTD0_DRE_vect) {
//    printf("DRE_vect tx_pos=%d tx_len=%d\r\n", tx_pos, tx_len);
    if (tx_pos < tx_len) {
        USARTD0.CTRLB &= ~USART_TXB8_bm;         // regular frame, not EOF
        USARTD0.DATA = tx_buf[tx_pos++];

    } else {
        USARTD0.STATUS = USART_RXCIF_bm | USART_TXCIF_bm;   // clear status bits
        USARTD0.CTRLB |= USART_TXB8_bm;        // send EOF frame
        USARTD0.DATA = 0;

        USARTD0.CTRLA &= ~(USART_DREINTLVL_gm);     // disable UDRE interrupt
        USARTD0.CTRLA |= USART_TXCINTLVL_MED_gc;    // enable TXC interrupt
//        printf("INFO: sent %d byte packet; status=%d\r\n", tx_pos, status);
    }
}

ISR(USARTD0_TXC_vect) {
//    const uint8_t status = USARTD0.STATUS;
//    printf("TXC_vect tx_pos=%d tx_len=%d status=%d\r\n", tx_pos, tx_len, status & USART_TXCIF_bm);
    toRx();
}

void toRx() {
    USARTD0.CTRLA &= ~(USART_DREINTLVL_gm);     // disable UDRE interrupt
    USARTD0.CTRLA &= ~USART_TXCINTLVL_gm;       // disable further TXC interrupts
    USARTD0.CTRLB |= USART_RXEN_bm;             // enable RX

    state = RX;
//    printf("INFO: TX -> RX\r\n");
    tx_len = 0;                                 // accept new outbound frame from application
    rx_pos = 0;                                 // rewind receive buffer
    set_alarm(100000, read_timeout);
}

void read_timeout() {
    printf("ERR: IrDA read timeout on: [");
    for (int i = 0; i < rx_pos; i++) {
        putchar(rx_buf[i]);
    }
    printf("]\r\n");
    toTx();
}

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
			 | 1 << USART_SBMODE_bp /* Stop Bit Mode: 2 stop bits */
			 | USART_CHSIZE_9BIT_gc /* Character size: 9 bit */
			 | 0 << USART_CHSIZE2_bp /* SPI Master Mode, Data Order: disabled */
			 | 1 << USART_CHSIZE1_bp /* SPI Master Mode, Clock Phase: enabled */
			 | USART_CMODE_IRDA_gc; /* IrDA Mode */

	USARTD0.CTRLB = 0 << USART_CLK2X_bp   /* Double transmission speed: disabled */
	                | 0 << USART_MPCM_bp  /* Multi-processor Communication Mode: disabled */
	                | 0 << USART_RXEN_bp  /* Receiver Enable: disabled */
	                | 1 << USART_TXEN_bp; /* Transmitter Enable: disabled */

    IRSD_set_level(true);           // disable IrDA transceiver

	return 0;
}

/**
 * \brief Enable RX and TX on IrDA.
 * 1. If supported by the clock system, enables the clock to the USART
 * 2. Enables the USART module by setting the RX and TX enable-bits in the USART control register
 *
 * \return Nothing
 */
void irda_enable(void (*receive_callback)(uint8_t *buf, int len)) {
    irda_read_callback = receive_callback;
//	USARTD0.CTRLB |= USART_RXEN_bm | USART_TXEN_bm;
	IRSD_set_level(false);	// enable IrDA
    toRx();
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
