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
#include "screen.h"
#include <compiler.h>

#define ROWCLK    (1 << 1)
#define ROWSDI    (1 << 4)
#define OE        (1 << 5)
#define LE        (1 << 6)

#define SEGCLK0   (1 << 0)
#define SEGCLK1   (1 << 1)
#define SEGCLK2   (1 << 7)

#define PB2 2

uint8_t row = 0;

void set_pixel(uint8_t x, uint8_t y, bool on) {

   if (on) {
      switch (x / 8) {
      case 0:
         screen[y][0] |= (0x80 >> x);
         break;
      case 1:
         screen[y][1] |= (0x8000 >> x);
         break;
      case 2:
         screen[y][2] |= (0x800000 >> x);
         break;
      default:
         break;
      }

   } else {
      switch (x / 8) {
      case 0:
         screen[y][0] &= ((0x80 >> x) ^ 0xff);
         break;
      case 1:
         screen[y][1] &= ((0x8000 >> x) ^ 0xff);
         break;
      case 2:
         screen[y][2] &= ((0x800000 >> x) ^ 0xff);
         break;
      default:
         break;
      }
   }
}

void clear_screen() {
   for (uint8_t r = 0; r < ROWS; r++) {
      screen[r][0] = screen[r][1] = screen[r][2] = 0;
   }
}

void redraw() {

   if (row != 0) {
      VPORT0.OUT |= ROWSDI;
   } else {
      VPORT0.OUT &= ~ROWSDI;
   }
   VPORT0.OUT |= ROWCLK;
   VPORT0.OUT &= ~ROWCLK;

   VPORT3.OUT = screen[row][0];
   VPORT2.OUT |= SEGCLK0;
   VPORT2.OUT &= ~SEGCLK0;

   VPORT3.OUT = screen[row][1];
   VPORT2.OUT |= SEGCLK1;
   VPORT2.OUT &= ~SEGCLK1;

   VPORT3.OUT = screen[row][2];
   VPORT2.OUT |= SEGCLK2;
   VPORT2.OUT &= ~SEGCLK2;

   VPORT0.OUT |= LE;
   VPORT0.OUT &= ~LE;
   row = (row + 1) % ROWS;

   PORTB_toggle_pin_level(PB2);  // for logic analyzer debugging
}
