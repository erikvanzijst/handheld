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

/*
 * Returns true if the button went from not pressed to pressed.
 */
bool was_pressed(button_t *button);

bool long_pressed(button_t *button);

#endif
