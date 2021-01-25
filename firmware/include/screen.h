#include <driver_init.h>
#include <compiler.h>

#define ROWS 16
#define COLS 24

volatile uint8_t screen[ROWS][3];

void redraw();
