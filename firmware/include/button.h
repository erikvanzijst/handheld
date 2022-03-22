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

extern button_t btn_start;
extern button_t btn_select;

extern button_t btn_left;
extern button_t btn_right;
extern button_t btn_up;
extern button_t btn_down;

extern button_t btn_x;
extern button_t btn_a;
extern button_t btn_y;
extern button_t btn_b;

/*
 * Returns true if the button went from not pressed to pressed.
 */
bool was_pressed(button_t *button);

/*
 * Returns a pointer to the button that was pressed. NULL otherwise. Does not
 * block.
 */
button_t * any_key();

bool long_pressed(button_t *button);

#endif
