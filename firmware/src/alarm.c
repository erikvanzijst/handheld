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
#include <stdint.h>
#include <stdio.h>
#include <atomic.h>
#include "tc.h"
#include "alarm.h"

void noop(void) {}

alarm_t *ALARM1 = &(alarm_t){
        .timer = &TCE0,
        .alarm_at_tick = 0,
        .ticks = 0,
        .cb = &noop
};
alarm_t *ALARM2 = &(alarm_t){
        .timer = &TCF0,
        .alarm_at_tick = 0,
        .ticks = 0,
        .cb = &noop
};

uint16_t US_PER_TICK = 1000000 / (F_CPU / 64);  // number of microseconds per timer tick (2 for 32MHz)

void alarm_ovf_isr(alarm_t * alarm) {
    alarm->ticks += (uint64_t)0x10000;

    if (alarm->cb != NULL) {
//        printf("OVF ticks=%lu, \r\n", (unsigned long)ticks);
        int64_t delta = (int64_t)(alarm->alarm_at_tick - alarm->ticks);
        if (delta >= 0 && delta < 0x10000) {
            // upcoming alarm falls within current interval
            alarm->timer->CTRLA = TC_CLKSEL_OFF_gc;                  // turn off the alarm timer
            alarm->timer->CTRLFSET = TC_CMD_RESET_gc;                // reset CNT to 0
//            printf("Scheduling for current period (ticks = %lu, delta = %u, US_PER_TICK = %lu)\r\n", (unsigned long)ticks, (uint16_t)delta, (1000000 / (F_CPU / 64)));
            alarm->timer->CCA = (uint16_t)delta;
            alarm->timer->INTCTRLB = TC_CCAINTLVL_MED_gc;            // enable CCA
            alarm->timer->CTRLA = TC_CLKSEL_DIV64_gc;                // turn on the alarm timer
        }
    }
}

void alarm_cca_isr(alarm_t * alarm) {
//    uint16_t cnt = alarm->timer->CNT;
//    ticks += cnt;
//    printf("ticks = %lu, CNT: %u\r\n", (unsigned long)ticks, cnt);
    alarm->timer->CTRLA = TC_CLKSEL_OFF_gc;                  // turn off the alarm timer
    if (alarm->cb != NULL) alarm->cb();
}

void set_alarm(alarm_t * alarm, uint64_t micros_from_now, void (*alarm_callback)(void)) {

    alarm->timer->CTRLA = TC_CLKSEL_OFF_gc;                  // turn off the alarm timer
    alarm->timer->CTRLFSET = TC_CMD_RESET_gc;
    alarm->alarm_at_tick = micros_from_now >> 1;           // US_PER_TICK is 2, so use fast bitshift division
    alarm->cb = alarm_callback;

    if (alarm->alarm_at_tick <= 0xffff) {
        // upcoming alarm falls within current interval
//        printf("Scheduling for current period (alarm_at_tick = %lu, US_PER_TICK = %lu)\r\n", (unsigned long)alarm_at_tick, (1000000 / (F_CPU / 64)));
        alarm->timer->CCA = alarm->alarm_at_tick;
        alarm->timer->INTCTRLB = TC_CCAINTLVL_MED_gc;        // enable CCA

    } else {
        // alarm is more than one period away
//        printf("Postponing to future period (alarm_at_tick = %lu, US_PER_TICK = %lu)\r\n", (unsigned long)alarm_at_tick, (1000000 / (F_CPU / 64)));
        alarm->timer->CCA = 1000;
        alarm->timer->INTCTRLA = TC_OVFINTLVL_MED_gc;        // enable overflow interrupt
        alarm->timer->INTCTRLB = 0;                          // disable all CCAs
    }
    alarm->ticks = 0;
    alarm->timer->CTRLA = TC_CLKSEL_DIV64_gc;                // turn on the alarm timer
}

bool clr_alarm(alarm_t * alarm)  {
    DISABLE_INTERRUPTS();
    const bool canceled = alarm->timer->CTRLA != TC_CLKSEL_OFF_gc;
    alarm->timer->CTRLA = TC_CLKSEL_OFF_gc;                  // turn off the alarm timer
    alarm->timer->CTRLFSET = TC_CMD_RESET_gc;
    alarm->cb = NULL;
    ENABLE_INTERRUPTS();
    return canceled;
}
