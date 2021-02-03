#ifndef BUTTON_INCLUDED
#define BUTTON_INCLUDED

#include <compiler.h>
#include <stdint.h>

typedef bool (*read_pin)();
typedef struct {
    read_pin get_level;
    bool curr_state;  // the current reading from the input pin
    bool last_state;  // the previous reading from the input pin
    uint64_t last_changed;
    uint64_t last_debounce;
} button_t;

button_t btn_start;
button_t btn_select;

button_t btn_left;
button_t btn_right;
button_t btn_up;
button_t btn_down;

button_t btn_x;
button_t btn_a;
button_t btn_y;
button_t btn_b;

/*
 * Returns true if the button went from not pressed to pressed.
 */
bool was_pressed(button_t *button);

/*
 * Returns true if any button was pressed. False otherwise. Does not block.
 */
bool any_key();

bool long_pressed(button_t *button);

#endif
