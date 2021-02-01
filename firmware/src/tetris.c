#include <compiler.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "button.h"
#include "font.h"
#include "screen.h"
#include "tetris.h"
#include "wallclock.h"

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define WIDTH 10    // width of tetris board

typedef struct {
    int x, y;
} vertex_t;

typedef struct {
    vertex_t vertex[4];
} shape_t;

typedef struct {
    shape_t shape[4];
} brickdef_t;

brickdef_t brickdefs[7] = {
  { // I
    .shape = {
      { .vertex = {{-1, 0}, {0, 0}, {1, 0}, {2, 0}} },
      { .vertex = {{0, 1}, {0, 0}, {0, -1}, {0, -2}} },
      { .vertex = {{-1, 0}, {0, 0}, {1, 0}, {2, 0}} },
      { .vertex = {{0, 1}, {0, 0}, {0, -1}, {0, -2}} }
    }
  },
  { // O
    .shape = {
      { .vertex = {{0, 0}, {0, 1}, {1, 0}, {1, 1}} },
      { .vertex = {{0, 0}, {0, 1}, {1, 0}, {1, 1}} },
      { .vertex = {{0, 0}, {0, 1}, {1, 0}, {1, 1}} },
      { .vertex = {{0, 0}, {0, 1}, {1, 0}, {1, 1}} }
    }
  },
  { // J
    .shape = {
      { .vertex = {{0, 0}, {1, 0}, {2, 0}, {2, 1}} },
      { .vertex = {{1, 1}, {1, 0}, {1, -1}, {0, 1}} },
      { .vertex = {{0, -1}, {0, 0}, {1, 0}, {2, 0}} },
      { .vertex = {{1, -1}, {1, 0}, {1, 1}, {2, -1}} }
    }
  },
  { // L
    .shape = {
      { .vertex = {{0, 1}, {0, 0}, {1, 0}, {2, 0}} },
      { .vertex = {{0, -1}, {1, -1}, {1, 0}, {1, 1}} },
      { .vertex = {{0, 0}, {1, 0}, {2, 0}, {2, -1}} },
      { .vertex = {{1, -1}, {1, 0}, {1, 1}, {2, 1}} }
    }
  },
  { // S
    .shape = {
      { .vertex = {{0, 1}, {1, 1}, {1, 0}, {2, 0}} },
      { .vertex = {{1, -1}, {1, 0}, {2, 0}, {2, 1}} },
      { .vertex = {{0, 1}, {1, 1}, {1, 0}, {2, 0}} },
      { .vertex = {{1, -1}, {1, 0}, {2, 0}, {2, 1}} }
    }
  },
  { // Z
    .shape = {
      { .vertex = {{0, 0}, {1, 0}, {1, 1}, {2, 1}} },
      { .vertex = {{1, -1}, {1, 0}, {0, 0}, {0, 1}} },
      { .vertex = {{0, 0}, {1, 0}, {1, 1}, {2, 1}} },
      { .vertex = {{1, -1}, {1, 0}, {0, 0}, {0, 1}} }
    }
  },
  { // T
    .shape = {
      { .vertex = {{0, 0}, {1, 0}, {2, 0}, {1, 1}} },
      { .vertex = {{1, -1}, {1, 0}, {1, 1}, {0, 0}} },
      { .vertex = {{0, 0}, {1, 0}, {2, 0}, {1, -1}} },
      { .vertex = {{1, -1}, {1, 0}, {1, 1}, {2, 0}} }
    }
  }
};

typedef struct {
    uint8_t id;
    uint8_t rotation;
    vertex_t location;
} fallingbrick_t;

/*
 * Returns the speed associated with the specified number of removed lines.
 * Speed in measured in delay ms.
 */
uint16_t getspeed(uint16_t lines) {
    return (uint16_t) max((-5.6 * lines + 550) + 50, 50);
}

void tetris() {
    printf("Clear screen\r\n");
    clear_screen();
    printf("Scrolling banner...\r\n");
    scroll("TETRIS       ", "", 5000);

    uint16_t lines = 0;
    uint16_t score = 0;
    uint16_t speed = getspeed(lines);
    uint64_t now = millis();
    uint16_t board[ROWS];
    memset(board, 0, sizeof(uint16_t) * ROWS);
    uint8_t next = (uint8_t)(rand() % 7);

    // paint background:
    printf("Drawing background...\r\n");
    for (uint8_t row = 0; row < ROWS; row++) {
        screen[row][0] = 2;
        screen[row][2] = 64;
    }

    printf("Game started...\r\n");

    _delay_ms(4000);
}
