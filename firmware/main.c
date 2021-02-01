#include <atmel_start.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <time.h>
#include <util/delay.h>
#include "font.h"
#include "screen.h"
#include "wallclock.h"

float dx = 0.9;
float dy = 0.5;
float x = 8;
float y = 8;

void bouncy_ball(uint64_t timeout) {
	const uint64_t start = millis();
	while (millis() - start < timeout) {
		clear_screen();
		
		if (((x+dx) < 0 || (x+dx) >= COLS)) {
			dx *= -1;
		}
		if (((y+dy) < 0 || (y+dy) >= ROWS)) {
			dy *= -1;
		}
		x += dx;
		y += dy;

		printf("ball at (%2d, %2d)\r\n", (uint8_t)x, (uint8_t)y);
		// printf("Milliseconds: %9lu, time: %x\r\n", millis(), time(NULL));

		set_pixel((uint8_t)x, (uint8_t)y, true);
		_delay_ms(50);

		// BATT_set_level(true);
		// _delay_ms(200);
		// BATT_set_level(false);
		// _delay_ms(200);
	}
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	OEB_set_level(false);

	while(true) {
		clear_screen();
		printf("Scroll some text...\r\n");
		scroll("Hello world      ", "", 7000);

		printf("Starting bouncy ball...\r\n");
		bouncy_ball(7000);
	}
}
