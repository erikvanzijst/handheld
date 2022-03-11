#include <atmel_start.h>
#include <stdint.h>
#include <stdio.h>
#include "1player.h"
#include "button.h"

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

    while(true) {
        single_player();
    }
}
