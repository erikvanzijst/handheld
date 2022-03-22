/*
MIT License

Copyright (c) 2022 Erik van Zijst <erik.van.zijst@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
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
    printf("Tetris firmware build: %s\r\n", VERSION_STR);
    printf("https://github.com/erikvanzijst/handheld\r\n");
    printf("Erik van Zijst <erik.van.zijst@gmail.com>\r\n\r\n");
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
