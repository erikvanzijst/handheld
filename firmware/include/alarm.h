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
#ifndef FIRMWARE_ALARM_H
#define FIRMWARE_ALARM_H


typedef struct {
    TC0_t *timer;
    volatile uint64_t ticks;
    volatile uint64_t alarm_at_tick;
    void (*cb)(void);
} alarm_t;

extern alarm_t *ALARM1;
extern alarm_t *ALARM2;

void alarm_ovf_isr(alarm_t * alarm);
void alarm_cca_isr(alarm_t * alarm);

/*
 * Single, global alarm that can be scheduled with microsecond precision.
 * Only one alarm can be active at any one time and calling `set_alarm`
 * cancels any active alarm.
 *
 * Alarms are not recurring.
 */
void set_alarm(alarm_t * alarm, uint64_t micros_from_now, void (*alarm_callback)(void));

/*
 * Cancels any active alarm.
 *
 * Returns true if an alarm was active, false otherwise.
 */
bool clr_alarm(alarm_t * alarm);

#endif //FIRMWARE_ALARM_H
