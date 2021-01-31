#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include "screen.h"
#include "font.h"
#include "wallclock.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	OEB_set_level(false);

	float dx = 0.9;
	float dy = 0.5;
	float x = 8;
	float y = 8;

	uint8_t buf[5];

	to_glyphs(buf, "a");
	// memcpy_P(buf, &(font[0]), 5);

	printf("Starting bouncy ball...\r\n");
	while (1) {
		clear_screen();

		scroll("Hello world  ", "", 0);
		
		if (((x+dx) < 0 || (x+dx) >= COLS)) {
			dx *= -1;
		}
		if (((y+dy) < 0 || (y+dy) >= ROWS)) {
			dy *= -1;
		}
		x += dx;
		y += dy;

		printf("ball at (%2d, %2d)\r\n", (uint8_t)x, (uint8_t)y);
		set_pixel((uint8_t)x, (uint8_t)y, true);
		_delay_ms(50);

		// BATT_set_level(true);
		// _delay_ms(200);
		// BATT_set_level(false);
		// _delay_ms(200);
	}
}
