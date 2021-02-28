#include <atmel_start.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "button.h"
#include "tetris.h"
#include "wallclock.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	OEB_set_level(false);

	bool is_sender = 1;	// Sender
	BATT_set_level(is_sender);

	char *hw = "Hello world!\r\n";
	uint8_t pos = 0;

	IRSD_set_level(false);	// enable IrDA
	uint64_t now = millis();

	printf("Starting in transmitter mode; press SELECT to switch...\r\n");
	while(true) {
		if (was_pressed(&btn_select)) {
			is_sender = !is_sender;
			BATT_set_level(is_sender);
			printf("Switched to %s mode\r\n", (is_sender ? "transmitter" : "receiver"));
			if (!is_sender) {
				// flush the receive buffer:
				while (USART_1_is_rx_ready()) USART_1_read();
			}
		}

		if (is_sender) {	// TX
			if (millis() - now > 333) {
				now = millis();
				if (USART_1_is_tx_ready()) {
					USART_1_write(hw[pos++]);
					pos %= strlen(hw);
				}
			}
		} else {			// RX
			if (USART_1_is_rx_ready()) {
				printf("%c", USART_1_read());
			}
		}
	}
}
