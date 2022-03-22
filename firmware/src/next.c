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
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "next.h"
#include "screen.h"
#include "tetrominos.h"

uint8_t upcoming[4];  // tetromino ids for the next 4 bricks (ring-buffer)
uint8_t head = 0;     // index of the current head of the ringbuffer

void print_queue()
{
    uint8_t pos = head;
    printf("Upcoming: ");
    do
    {
        printf("%d ", upcoming[pos]);
        pos = (pos + 1) % sizeof(upcoming);
    } while (pos != head);
    printf("\r\n");
}

void initialize_upcoming()
{
    for (uint8_t i = 0; i < sizeof(upcoming); i++) {
        upcoming[i] = (uint8_t)(rand() % 7);
    }
    head = 0;
}

void draw_upcoming()
{
    // clear preview area:
    for (uint8_t row = 0; row < ROWS; row++) {
        screen[row][2] &= 0xc0;
    }

    // paint the next tetrominos:
    uint8_t pos = head;
    uint8_t cnt = 0;
    do
    {
        for (uint8_t i = 0; i < 4; i++)
        {
            set_pixel(brickdefs[upcoming[pos]].shape[0].vertex[i].x + 20,
                      brickdefs[upcoming[pos]].shape[0].vertex[i].y + cnt * 4 + 1,
                      true);
        }
        cnt++;
        pos = (pos + 1) % sizeof(upcoming);
    } while (pos != head);
}

uint8_t take_upcoming()
{
    const uint8_t retval = upcoming[head];
    upcoming[head] = (uint8_t)(rand() % 7); // new tail
    head = (head + 1) % sizeof(upcoming);
    return retval;
}
