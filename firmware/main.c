#include <atmel_start.h>
#include <util/delay.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	OEB_set_level(false);
	ROWSDI_set_level(false);
	ROWCLK_set_level(false);
	ROWSDI_set_level(true);

	for (uint8_t i = 0; i < 16; i++) {
		_delay_ms(1);
		ROWCLK_set_level(false);
		_delay_ms(1);
		ROWCLK_set_level(true);
		_delay_ms(1);
	}
	LE_set_level(false);
	_delay_ms(1);
	LE_set_level(true);
	PORTF.OUT = 0;
	// D0_set_level(false);
	// D1_set_level(false);
	// D2_set_level(false);
	// D3_set_level(false);
	// D4_set_level(true);
	// D5_set_level(true);
	// D6_set_level(true);
	// D7_set_level(true);

	// D0_set_level(true);
	// D1_set_level(true);

	SEGCLK0_set_level(true);
	SEGCLK1_set_level(true);
	SEGCLK2_set_level(true);
	SEGCLK0_set_level(false);
	SEGCLK1_set_level(false);
	SEGCLK2_set_level(false);

	uint8_t row = 0;
	while (1) {
		ROWSDI_set_level(row != 0);
		ROWCLK_set_level(false);
		ROWCLK_set_level(true);

		for (uint8_t col = 0; col < 24; col++) {
			PORTF.OUT = (col / 8 == 2) ? (1 << (col % 8)) : 0;
			SEGCLK0_set_level(true);
			SEGCLK0_set_level(false);

			PORTF.OUT = (col / 8 == 1) ? (1 << (col % 8)) : 0;
			SEGCLK1_set_level(true);
			SEGCLK1_set_level(false);

			PORTF.OUT = (col / 8 == 0) ? (1 << (col % 8)) : 0;
			SEGCLK2_set_level(true);
			SEGCLK2_set_level(false);

			_delay_ms(20);
		}
		// D0_set_level(true);
		// D1_set_level(true);
		// D2_set_level(true);
		// D3_set_level(true);
		// D4_set_level(true);
		// D5_set_level(true);
		// D6_set_level(true);
		// D7_set_level(true);

		LE_set_level(false);
		LE_set_level(true);

		// BATT_set_level(true);
		// _delay_ms(10);
		// BATT_set_level(false);
		// _delay_ms(10);

		row = (row + 1) % 16;
	}
}
