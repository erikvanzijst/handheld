#include <atmel_start.h>
#include <stdio.h>
#include <font.h>
#include <wallclock.h>
#include <screen.h>
#include <util.h>
#include "1player.h"
#include "2player.h"
#include "button.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
    OEB_set_level(false);

    clear_screen();
    printf("Tetris firmware %s starting up...\r\n", VERSION_STR);
    scroll("TETRIS      ", "", -1);
    srand((unsigned int)millis());  // use human button press delay as random seed

    while (true) {
        printf("Game type selection screen.\r\n");
        clear_screen();
        button_t * button = scroll("A:1p  ", "B:2p  ", -1);

        if (button == &btn_a) {
            printf("Launching single player mode...\r\n");
            while(true) single_player();
        } else if (button == &btn_b) {
            printf("Launching multiplayer mode...\r\n");
            while(true) multi_player();
        } else {
            printf("Invalid selection\r\n");
        }
    }
}
