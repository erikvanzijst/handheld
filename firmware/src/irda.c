/*
MIT License

Copyright (c) 2022 Erik van Zijst <erik.van.zijst@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <compiler.h>
#include <atomic.h>
#include <stdio.h>
#include <string.h>
#include "alarm.h"
#include "atmel_start_pins.h"
#include "irda.h"
#include "util.h"

volatile link_stats_t link_stats = {
        .bytes_in = 0,
        .bytes_out = 0,
        .crc_errors = 0,
        .timeouts = 0
};

static void (*irda_read_callback)(uint8_t *buf, uint16_t len) = NULL;

void toTx();
void toRx();
void read_timeout();
void enableUDRE();

static volatile uint8_t rx_buf[IRDA_MAXBUF + 2];
static volatile uint8_t tx_buf[IRDA_MAXBUF];
static volatile int rx_pos;
static volatile int tx_pos;
static volatile uint16_t tx_len;

link_stats_t * irda_stats(link_stats_t *stats) {
    DISABLE_INTERRUPTS();
    stats->bytes_out = link_stats.bytes_out;
    stats->bytes_in = link_stats.bytes_in;
    stats->timeouts = link_stats.timeouts;
    stats->crc_errors = link_stats.crc_errors;
    ENABLE_INTERRUPTS();
    return stats;
}

bool irda_write_available() {
    return !tx_len;
}

int irda_write(uint8_t *buf, uint16_t len) {

    while (tx_len);
    uint16_t l = min(len, IRDA_MAXBUF);
    memcpy(tx_buf, buf, l);

    DISABLE_INTERRUPTS();
    tx_pos = 0;
    tx_len = l;
    ENABLE_INTERRUPTS();
    return (int)tx_len;
}

ISR(USARTD0_RXC_vect) {
    const uint8_t status = USARTD0.STATUS;
    const bool eof = status & USART_RXB8_bm;
    const uint8_t data = USARTD0.DATA;

//    printf("RXC_vect STATUS=%d data=%d state=%d\r\n", status, data, state);
    if (status & USART_RXCIF_bm) {
        if (eof) {            // end-of-packet frame
            USARTD0.CTRLB &= ~USART_RXEN_bm;            // disable RX

            if (rx_pos > 1 && irda_read_callback != NULL) {
                uint16_t eop = rx_pos - 2;
                uint8_t *pi;
                uint16_t n = eop;
                pi = rx_buf;
                while (n--) CRC.DATAIN = *pi++;
                CRC.STATUS |= CRC_BUSY_bm;                  // stop the CRC computation

                if (CRC.CHECKSUM0 == *pi++ && CRC.CHECKSUM1 == *pi) {
                    (*irda_read_callback)(rx_buf, eop);  // deliver packet to application
                    link_stats.bytes_in += eop;
                } else {
                    link_stats.crc_errors++;
                }
            }

            // We have a half-duplex channel. Give our peer 1ms to transition out of TX
            // mode and enable its receiver and interrupts before we send our first frame.
            set_alarm(ALARM1, 1000, toTx);

        } else {
            if (rx_pos >= IRDA_MAXBUF) {
                printf("ERR: IrDA receive overflow\r\n");
            } else {
                rx_buf[rx_pos++] = data;
            }
            set_alarm(ALARM1, 1000, read_timeout);
        }
    } else {
        printf("ERR: USARTD0_RXC_vect with USART_RXCIF_bm unset!\r\n");
    }
}

void enableUDRE() {
    USARTD0.CTRLA |= USART_DREINTLVL_MED_gc;    // enable the UDRE interrupt now
}

void toTx() {
    clr_alarm(ALARM1);
    USARTD0.CTRLB &= ~USART_RXEN_bm;            // disable RX

    CRC.CTRL = CRC_SOURCE_DISABLE_gc;           // disable CRC engine
    CRC.CTRL = CRC_RESET_RESET0_gc;             // reset CRC state
    CRC.CTRL = CRC_SOURCE_IO_gc;                // configure for CRC-16

//    printf("INFO: RX -> TX\r\n");

    USARTD0.CTRLA &= ~USART_TXCINTLVL_gm;       // disable TXC interrupt

    enableUDRE();                               // start sending pending frame
}

ISR(USARTD0_DRE_vect) {
    if (tx_len && tx_pos < tx_len + 2) {
        USARTD0.CTRLB &= ~USART_TXB8_bm;        // regular frame, not EOF

        if (tx_pos < tx_len) {
            CRC.DATAIN = tx_buf[tx_pos];
            USARTD0.DATA = tx_buf[tx_pos];
        } else if (tx_pos == tx_len) {          // first CRC-16 byte
            CRC.STATUS |= CRC_BUSY_bm;          // stop the CRC computation
            USARTD0.DATA = CRC.CHECKSUM0;
        } else {                                // second CRC-16 byte
            USARTD0.DATA = CRC.CHECKSUM1;
        }
        tx_pos++;

    } else {
        USARTD0.STATUS = USART_RXCIF_bm | USART_TXCIF_bm;   // clear status bits
        USARTD0.CTRLB |= USART_TXB8_bm;             // send EOF frame
        USARTD0.DATA = 0;

        USARTD0.CTRLA &= ~USART_DREINTLVL_gm;       // disable UDRE interrupt
        USARTD0.CTRLA |= USART_TXCINTLVL_MED_gc;    // enable TXC interrupt
        link_stats.bytes_out += tx_len;
    }
}

ISR(USARTD0_TXC_vect) {
    toRx();
}

void toRx() {
    CRC.CTRL = CRC_SOURCE_DISABLE_gc;           // disable CRC engine
    CRC.CTRL = CRC_RESET_RESET0_gc;             // reset CRC state
    CRC.CTRL = CRC_SOURCE_IO_gc;                // CRC-16

    USARTD0.CTRLA &= ~USART_DREINTLVL_gm;       // disable UDRE interrupt
    USARTD0.CTRLA &= ~USART_TXCINTLVL_gm;       // disable further TXC interrupts
    USARTD0.CTRLB |= USART_RXEN_bm;             // enable RX

//    printf("INFO: TX -> RX\r\n");
    tx_len = 0;                                 // accept new outbound frame from application
    rx_pos = 0;                                 // rewind receive buffer
    set_alarm(ALARM1, 100000, read_timeout);
}

void read_timeout() {
    link_stats.timeouts++;
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
	                | 1 << USART_TXEN_bp; /* Transmitter Enable: always enabled */

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
void irda_enable(void (*receive_callback)(uint8_t *buf, uint16_t len)) {
    irda_read_callback = receive_callback;
	IRSD_set_level(false);	// enable IrDA
    toRx();
}
