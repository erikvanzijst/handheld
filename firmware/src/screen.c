#include "screen.h"
#include <compiler.h>

#define ROWCLK 1
#define ROWSDI 4
#define OE = 5
#define LE 6

#define SEGCLK0 0
#define SEGCLK1 1
#define SEGCLK2 2

#define PB2 2

uint8_t row = 0;

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

   // PORTB_toggle_pin_level(PB2);  // for logic analyzer debugging
}
