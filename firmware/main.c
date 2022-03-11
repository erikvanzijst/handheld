#include <atmel_start.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include "button.h"
#include "irda.h"
#include "wallclock.h"

void irda_receive(uint8_t *buf, uint16_t len) {
    BATT_toggle_level();
    printf("INFO: %d byte packet received: [", len);
    for (uint16_t i = 0; i < len; i++) {
        putchar(buf[i]);
    }
    printf("]\r\n");
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

    OEB_set_level(false);
    char buf[IRDA_MAXBUF + 1];

	char *hw = "Hello world!  Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    irda_enable(irda_receive);
//	IRSD_set_level(false);	// enable IrDA

	printf("Sending chars over IrDA...\r\n");
	while(true) {
        snprintf(buf, IRDA_MAXBUF + 1, "%lu: %s", (unsigned long)millis(), hw);
        irda_write((uint8_t *)buf, strlen(buf));

        _delay_ms(200);
    }
}
