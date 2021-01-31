#include <atmel_start.h>
#include <util/delay.h>
#include "screen.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	OEB_set_level(false);

	float dx = 0.9;
	float dy = 0.5;
	float x = 8;
	float y = 8;

	while (1) {
		clear_screen();
		
		if (((x+dx) < 0 || (x+dx) >= COLS)) {
			dx *= -1;
		}
		if (((y+dy) < 0 || (y+dy) >= ROWS)) {
			dy *= -1;
		}
		x += dx;
		y += dy;

		set_pixel((uint8_t)x, (uint8_t)y, true);
		_delay_ms(50);

		// BATT_set_level(true);
		// _delay_ms(200);
		// BATT_set_level(false);
		// _delay_ms(200);
	}
}
