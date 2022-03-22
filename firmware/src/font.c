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
#include <avr/pgmspace.h>
#include <compiler.h>
#include <ctype.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <util.h>
#include "button.h"
#include "screen.h"
#include "wallclock.h"

// partial minimalist 5x5 font from https://www.dafont.com/5x5.font
const uint8_t font[46][5] PROGMEM = {
  {0x00, 0x00, 0x1f, 0x00, 0x00}, // -
  {0x00, 0x00, 0x00, 0x00, 0x04}, // .
  {0x02, 0x02, 0x04, 0x08, 0x08}, // /

  {0x1f, 0x13, 0x15, 0x19, 0x1f}, // 0
  {0x04, 0x0c, 0x04, 0x04, 0x0e}, // 1
  {0x1e, 0x01, 0x0e, 0x10, 0x1f}, // 2
  {0x1f, 0x01, 0x0e, 0x01, 0x1f}, // 3
  {0x10, 0x10, 0x14, 0x1f, 0x04}, // 4
  {0x1f, 0x10, 0x1e, 0x01, 0x1e}, // 5
  {0x1f, 0x10, 0x1f, 0x11, 0x1f}, // 6
  {0x1f, 0x01, 0x02, 0x04, 0x04}, // 7
  {0x1f, 0x11, 0x1f, 0x11, 0x1f}, // 8
  {0x1f, 0x11, 0x1f, 0x01, 0x1f}, // 9

  {0x0, 0x04, 0x0, 0x04, 0x0},    // :
  {0x0, 0x04, 0x0, 0x04, 0x04},   // ;
  {0x00, 0x00, 0x00, 0x00, 0x00},  // <
  {0x00, 0x1f, 0x00, 0x1f, 0x00},  // =
  {0x00, 0x00, 0x00, 0x00, 0x00},  // >
  {0x00, 0x00, 0x00, 0x00, 0x00},  // ?
  {0x00, 0x00, 0x00, 0x00, 0x00},  // fake space

  {0x1f, 0x11, 0x11, 0x1f, 0x11}, // A
  {0x1f, 0x11, 0x1e, 0x11, 0x1f}, // B
  {0x1f, 0x10, 0x10, 0x10, 0x1f}, // C
  {0x1e, 0x11, 0x11, 0x11, 0x1e}, // D
  {0x1f, 0x10, 0x1e, 0x10, 0x1f}, // E
  {0x1f, 0x10, 0x1e, 0x10, 0x10}, // F
  {0x1f, 0x10, 0x13, 0x11, 0x1f}, // G
  {0x11, 0x11, 0x1f, 0x11, 0x11}, // H
  {0x1f, 0x04, 0x04, 0x04, 0x1f}, // I
  {0x03, 0x01, 0x01, 0x11, 0x1f}, // J
  {0x11, 0x12, 0x1c, 0x12, 0x11}, // K
  {0x10, 0x10, 0x10, 0x10, 0x1f}, // L
  {0x11, 0x1b, 0x15, 0x11, 0x11}, // M
  {0x11, 0x19, 0x15, 0x13, 0x11}, // N
  {0x0e, 0x11, 0x11, 0x11, 0x0e}, // O
  {0x1e, 0x11, 0x1e, 0x10, 0x10}, // P
  {0x1f, 0x11, 0x11, 0x1f, 0x04}, // Q
  {0x1e, 0x11, 0x1e, 0x11, 0x11}, // R
  {0x1f, 0x10, 0x1f, 0x01, 0x1f}, // S
  {0x1f, 0x04, 0x04, 0x04, 0x04}, // T
  {0x11, 0x11, 0x11, 0x11, 0x1f}, // U
  {0x11, 0x11, 0x0a, 0x0a, 0x04}, // V
  {0x11, 0x11, 0x15, 0x15, 0x0a}, // W
  {0x11, 0x0a, 0x04, 0x0a, 0x11}, // X
  {0x11, 0x11, 0x0a, 0x04, 0x04}, // Y
  {0x1f, 0x02, 0x04, 0x08, 0x1f}  // Z
};

int to_glyphs(uint8_t *glyphs, const char *str) {
  for (unsigned int i = 0; i < strlen(str); i++) {
    const uint8_t j = ((uint8_t)str[i]) == 0x20 ? 19 : ((uint8_t)toupper(str[i])) - 45; // space is mapped to @
    if (j < 0 || j > sizeof(font) / 5) {
      printf("Invalid character! 0x%0.2x\r\n", str[i]);
      return -1;
    }
    memcpy_P(glyphs + i*5, &(font[j]), 5);
  }
  return 0;
}

button_t * scroll(const char *line1, const char *line2, long timeout) {
    const uint64_t start = millis();
    typedef struct {
        unsigned int pos;
        uint8_t row;
        uint8_t *glyphs;
        int16_t len;
    } line_t;

    line_t lines[2];
    uint8_t glyphs1[strlen(line1) * 5];
    uint8_t glyphs2[strlen(line2) * 5];
    button_t * button = NULL;

    if (to_glyphs((uint8_t *) glyphs1, line1) || to_glyphs((uint8_t *) glyphs2, line2)) {
        return NULL;
    }
    lines[0].pos = 0;
    lines[0].row = strlen(line2) == 0 ? 5 : 2;
    lines[0].glyphs = glyphs1;
    lines[0].len = strlen(line1);
    lines[1].pos = 0;
    lines[1].row = strlen(line1) == 0 ? 5 : 10;
    lines[1].glyphs = glyphs2;
    lines[1].len = strlen(line2);

    while ((timeout == -1 || (millis() - start) < timeout)) {
        if ((button = any_key()) != NULL) {
            return button;
        }

        for (uint8_t i = 0; i < 2; i++) {
            for (int16_t r = 4; lines[i].len && r >= 0; r--) {
                uint8_t row = lines[i].row + r;
                screen[row][0] <<= 1;
                screen[row][0] |= (screen[row][1] >> 7);
                screen[row][1] <<= 1;
                screen[row][1] |= (screen[row][2] >> 7);
                screen[row][2] <<= 1;

                screen[row][2] |= ((*(lines[i].glyphs + ((lines[i].pos / 6) * 5) + r) & (0x20 >> (lines[i].pos % 6)))
                                   ? 1 : 0);
            }
            lines[i].pos = (lines[i].pos + 1) % (lines[i].len * 6);
        }
        _delay_ms(75);
    }
    return NULL;
}

int say(const char *str) {
    uint8_t glyphs[strlen(str) * 5];
    if (to_glyphs((uint8_t *) glyphs, str)) {
        return -1;
    }

    uint32_t rows[5] = {0, 0, 0, 0, 0};
    for (int row = 0; row < 5; row++) {
        for (unsigned int i = 0; i < min(strlen(str), 4); i++) {
            rows[row] |= ((uint32_t)glyphs[5 * i + row]) << (26 - (6 * i));
        }
    }

    screen[4][0] = screen[4][1] = screen[4][2] = 0;
    for (int16_t r = 4; r >= 0; r--) {
        uint8_t row = 5 + r;
        screen[row][0] = rows[r] >> 24;
        screen[row][1] = (rows[r] >> 16) & 0xff;
        screen[row][2] = (rows[r] >> 8) & 0xff;
    }
    screen[10][0] = screen[10][1] = screen[10][2] = 0;
    return 0;
}
