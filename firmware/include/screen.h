#ifndef SCREEN_INCLUDED
#define SCREEN_INCLUDED

#include <driver_init.h>
#include <compiler.h>

#define ROWS 16
#define COLS 24

uint8_t screen[ROWS][3];

void clear_screen();
void set_pixel(uint8_t x, uint8_t y, bool on);
void redraw();

#endif
