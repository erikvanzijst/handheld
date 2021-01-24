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

	uint8_t row = 0;
	while (1) {
		ROWSDI_set_level(row != 0);
		ROWCLK_set_level(false);
		ROWCLK_set_level(true);

		D0_set_level(true);
		D1_set_level(true);
		D2_set_level(true);
		D3_set_level(true);
		D4_set_level(true);
		D5_set_level(true);
		D6_set_level(true);
		D7_set_level(true);

		SEGCLK0_set_level(true);
		SEGCLK1_set_level(true);
		SEGCLK2_set_level(true);
		SEGCLK0_set_level(false);
		SEGCLK1_set_level(false);
		SEGCLK2_set_level(false);

		LE_set_level(false);
		LE_set_level(true);

		BATT_set_level(true);
		_delay_ms(10);
		BATT_set_level(false);
		_delay_ms(10);

		row = (row + 1) % 16;
	}
}
