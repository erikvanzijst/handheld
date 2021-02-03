#include <atmel_start_pins.h>
#include <stdint.h>
#include "button.h"
#include "wallclock.h"

#define DEBOUNCE_DELAY 50
#define LONG_PRESS 400

button_t btn_start = {START_get_level, false, false, 0, 0};
button_t btn_select = {SELECT_get_level, false, false, 0, 0};

button_t btn_left = {SW_LEFT_get_level, false, false, 0, 0};
button_t btn_right = {SW_RIGHT_get_level, false, false, 0, 0};
button_t btn_up = {SW_UP_get_level, false, false, 0, 0};
button_t btn_down = {SW_DOWN_get_level, false, false, 0, 0};

button_t btn_x = {SW_X_get_level, false, false, 0, 0};
button_t btn_a = {SW_A_get_level, false, false, 0, 0};
button_t btn_y = {SW_Y_get_level, false, false, 0, 0};
button_t btn_b = {SW_B_get_level, false, false, 0, 0};

bool any_key() {
    return
        was_pressed(&btn_start) ||
        was_pressed(&btn_select) ||

        was_pressed(&btn_up) ||
        was_pressed(&btn_down) ||
        was_pressed(&btn_left) ||
        was_pressed(&btn_right) ||

        was_pressed(&btn_a) ||
        was_pressed(&btn_b) ||
        was_pressed(&btn_x) ||
        was_pressed(&btn_y);
}

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
