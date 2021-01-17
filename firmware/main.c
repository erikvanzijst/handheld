#include <atmel_start.h>
#include <util/delay.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	OEB_set_level(false);
	ROWSDI_set_level(false);
	ROWCLK_set_level(false);

	for (uint8_t i = 0; i < 16; i++) {
		ROWSDI_set_level(i != 15);
		_delay_ms(1);
		ROWCLK_set_level(false);
		_delay_ms(1);
		ROWCLK_set_level(true);
		_delay_ms(1);
	}
	LE_set_level(false);
	_delay_ms(1);
	LE_set_level(true);

	SEGCLK0_set_level(false);
	SEGCLK1_set_level(false);
	SEGCLK2_set_level(false);

	D0_set_dir(PORT_DIR_OFF);
	D1_set_dir(PORT_DIR_OFF);
	D2_set_dir(PORT_DIR_OFF);
	D3_set_dir(PORT_DIR_OFF);
	D4_set_dir(PORT_DIR_OFF);
	D5_set_dir(PORT_DIR_OFF);
	D6_set_dir(PORT_DIR_OFF);
	D7_set_dir(PORT_DIR_OFF);

	while (1) {
		BATT_set_level(true);
		_delay_ms(500);
		BATT_set_level(false);
		_delay_ms(500);
	}
}
