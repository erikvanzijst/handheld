#include <atmel_start.h>
#include "tetris.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	OEB_set_level(false);

	// button_t start = {START_get_level, false, false, 0, 0};
	// if (was_pressed(&start)) {
	// 	BATT_toggle_level();
	// }

	while(true) {
		tetris();
	}
}
