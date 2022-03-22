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

button_t * any_key() {
    if (was_pressed(&btn_start)) {
        return &btn_start;
    } else if (was_pressed(&btn_select)) {
        return &btn_start;

    } else if (was_pressed(&btn_up)) {
        return &btn_up;
    } else if (was_pressed(&btn_down)) {
        return &btn_down;
    } else if (was_pressed(&btn_left)) {
        return &btn_left;
    } else if (was_pressed(&btn_right)) {
        return &btn_right;

    } else if (was_pressed(&btn_a)) {
        return &btn_a;
    } else if (was_pressed(&btn_b)) {
        return &btn_b;
    } else if (was_pressed(&btn_x)) {
        return &btn_x;
    } else if (was_pressed(&btn_y)) {
        return &btn_y;
    } else {
        return NULL;
    }
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
