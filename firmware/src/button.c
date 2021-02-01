#include <stdint.h>
#include "button.h"
#include "wallclock.h"

#define DEBOUNCE_DELAY 50
#define LONG_PRESS 400

bool was_pressed(button_t *button) {
    const bool value = button->get_level();

    if (value != button->last_state) {
        button->last_debounce = millis();
        button->last_state = value;
    }

    if ((millis() - button->last_debounce) > DEBOUNCE_DELAY && value != button->curr_state) {
        button->curr_state = value;
        button->last_changed = millis();
        if (button->curr_state) {
            return true;
        }
    }
    return false;
}

bool long_pressed(button_t *button) {
  return button->curr_state && (millis() - button->last_changed) >= LONG_PRESS;
}
