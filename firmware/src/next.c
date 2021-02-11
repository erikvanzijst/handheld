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
    // initialize the upcoming queue:
    for (uint8_t i = 0; i < sizeof(upcoming); i++)
    {
        upcoming[i] = (uint8_t)(rand() % 7);
    }
    head = 0;
    printf("Initializing upcoming tetrominos: ");
    print_queue();
}

void draw_upcoming()
{
    // clear preview area:
    for (uint8_t row = 0; row < ROWS; row++)
    {
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
    print_queue();
    return retval;
}
