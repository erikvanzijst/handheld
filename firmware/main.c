#include <atmel_start.h>
#include <util/delay.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {
		BATT_set_level(true);
		_delay_ms(500);
		BATT_set_level(false);
		_delay_ms(500);
	}
}
