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
#include <compiler.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "button.h"
#include "font.h"
#include "melody.h"
#include "screen.h"
#include "sound.h"
#include "tetris.h"
#include "tetrominos.h"
#include "util.h"

#define WIDTH 10    // width of tetris board

vertex_t down = {0, 1};
vertex_t left = {-1, 0};
vertex_t right = {1, 0};
vertex_t identity = {0, 0};
uint16_t linevalue[] = {0, 40, 100, 300, 1200};

void materialize(shape_t *dest, volatile fallingbrick_t *brick) {
  for (uint8_t i = 0; i < 4; i++) {
    dest->vertex[i].x = brickdefs[brick->id].shape[brick->rotation].vertex[i].x + brick->location.x;
    dest->vertex[i].y = brickdefs[brick->id].shape[brick->rotation].vertex[i].y + brick->location.y;
  }
}

bool fits(fallingbrick_t *brick, const volatile uint16_t *board) {
  shape_t shape;
  materialize(&shape, brick);

  for (uint8_t i = 0; i < 4; i++) {
    if (shape.vertex[i].y < 0 || shape.vertex[i].y >= ROWS || shape.vertex[i].x < 0 || shape.vertex[i].x >= WIDTH ||
        (board[shape.vertex[i].y] & (0x8000 >> shape.vertex[i].x))) {
      return false;
    }
  }
  return true;
}

bool move(fallingbrick_t *dest, volatile fallingbrick_t *src, int rot, vertex_t *vector, volatile uint16_t *board) {
  memcpy(dest, (void *)src, sizeof(fallingbrick_t));

  dest->rotation = (dest->rotation + rot + 4) % 4;
  dest->location.x += vector->x;
  dest->location.y += vector->y;

  return fits(dest, board);
}

uint8_t merge(volatile fallingbrick_t *brick, volatile uint16_t *board) {
    uint8_t removed = 0;
    shape_t shape;
    materialize(&shape, brick);
    for (uint8_t i = 0; i < 4; i++) {
        board[shape.vertex[i].y] |= (0x8000 >> shape.vertex[i].x);
    }

    // remove completed lines:
    int row = ROWS - 1;
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i] < 0xffc0) {
            board[row--] = board[i];
        } else {
            removed++;
        }
    }
    for (; row >= 0; row--) {
        board[row] = 0;
    }
    return removed;
}

/*
 * Returns the speed associated with the specified number of removed lines.
 * Speed in measured in delay ms.
 */
uint16_t get_speed(uint16_t lines) {
  return (uint16_t) max((-5.6 * lines + 550) + 50, 50);
}

void pause() {
  if (was_pressed(&btn_start) || was_pressed(&btn_y)) {
    uint8_t saved[ROWS][3];

    printf("Paused...\r\n");
    memcpy(saved, screen, sizeof(screen));
    clear_screen();

    scroll(
        "Paused              ",
        "          Paused    ",
        -1);

    memcpy(screen, saved, sizeof(screen));
    printf("Resuming...\r\n");
  }
}

// TODO: Move to 1player.c
void gameover(const uint16_t * board, uint16_t score, uint32_t hiscore) {
    char top[] = "YOU :             ";
    char bottom[] = "BEST:             ";

    _delay_ms(1000);
    clear_screen();
    play_melody(&gameover_melody, 1);

    itoa(hiscore, (char *) (bottom + 5), 10);
    strcpy((char *) (bottom + strlen(bottom)), "  ");

    itoa(score, (char *) (top + 5), 10);
    memset((char *) (top + strlen(top)), 0x20, sizeof(top) - strlen(top));
    top[strlen(bottom)] = 0;

    printf("GAME OVER\r\n");
    printf("Score: %u\r\n", score);
    printf("Hiscore: %lu\r\n", hiscore);
    dump_boad(board);

    any_key();  // clear button state
    scroll(top, bottom, -1);
}

void dump_boad(const uint16_t * board) {
    for (uint8_t row = 0; row < ROWS; row++) {
        dump_row(board[row]);
    }
}

void dump_row(const uint16_t row) {
    for (uint16_t bm = 0x8000; bm >= 0x40; bm = bm >> 1) {
        printf("%c ", (row & bm) ? '#' : '.');
    }
    printf("\r\n");
}
