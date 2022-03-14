#include <stdint.h>
#include <stdio.h>
#include <atomic.h>
#include "tc.h"
#include "alarm.h"


uint16_t US_PER_TICK = 1000000 / (F_CPU / 64);  // number of microseconds per timer tick
volatile uint64_t ticks = 0;
volatile uint64_t alarm_at_tick = 0;

void noop() {}
void (*alarm_cb)(void) = noop;

void alarm_ovf_isr() {
    ticks += (uint64_t)0x10000;

    if (alarm_cb != NULL) {
//        printf("OVF ticks=%lu, \r\n", (unsigned long)ticks);
        int64_t delta = (int64_t)(alarm_at_tick - ticks);
        if (delta >= 0 && delta < 0x10000) {
            // upcoming alarm falls within current interval
            TCF0.CTRLA = TC_CLKSEL_OFF_gc;                  // turn off the alarm timer
            TCF0.CTRLFSET = TC_CMD_RESET_gc;                // reset CNT to 0
//            printf("Scheduling for current period (ticks = %lu, delta = %u, US_PER_TICK = %lu)\r\n", (unsigned long)ticks, (uint16_t)delta, (1000000 / (F_CPU / 64)));
            TCF0.CCA = (uint16_t)delta;
            TCF0.INTCTRLB = TC_CCAINTLVL_MED_gc;            // enable CCA
            TCF0.CTRLA = TC_CLKSEL_DIV64_gc;                // turn on the alarm timer
        }
    }
}

void alarm_cca_isr() {
//    uint16_t cnt = TCF0.CNT;
//    ticks += cnt;
//    printf("ticks = %lu, CNT: %u\r\n", (unsigned long)ticks, cnt);
    TCF0.CTRLA = TC_CLKSEL_OFF_gc;                  // turn off the alarm timer
    if (alarm_cb != NULL) alarm_cb();
}

void set_alarm(uint64_t micros_from_now, void (*alarm_callback)(void)) {
    DISABLE_INTERRUPTS();

    TCF0.CTRLA = TC_CLKSEL_OFF_gc;                  // turn off the alarm timer
    TCF0.CTRLFSET = TC_CMD_RESET_gc;
    alarm_at_tick = micros_from_now >> 1;           // US_PER_TICK is 2, so use fast bitshift division
    alarm_cb = alarm_callback;

    if (alarm_at_tick <= 0xffff) {
        // upcoming alarm falls within current interval
//        printf("Scheduling for current period (alarm_at_tick = %lu, US_PER_TICK = %lu)\r\n", (unsigned long)alarm_at_tick, (1000000 / (F_CPU / 64)));
        TCF0.CCA = alarm_at_tick;
        TCF0.INTCTRLB = TC_CCAINTLVL_MED_gc;        // enable CCA

    } else {
        // alarm is more than one period away
//        printf("Postponing to future period (alarm_at_tick = %lu, US_PER_TICK = %lu)\r\n", (unsigned long)alarm_at_tick, (1000000 / (F_CPU / 64)));
        TCF0.CCA = 1000;
        TCF0.INTCTRLA = TC_OVFINTLVL_MED_gc;        // enable overflow interrupt
        TCF0.INTCTRLB = 0;                          // disable all CCAs
    }
    ticks = 0;
    ENABLE_INTERRUPTS();
    TCF0.CTRLA = TC_CLKSEL_DIV64_gc;                // turn on the alarm timer
}

bool clr_alarm()  {
    DISABLE_INTERRUPTS();
    const bool canceled = TCF0.CTRLA != TC_CLKSEL_OFF_gc;
    TCF0.CTRLA = TC_CLKSEL_OFF_gc;                  // turn off the alarm timer
    TCF0.CTRLFSET = TC_CMD_RESET_gc;
    alarm_cb = NULL;
    ENABLE_INTERRUPTS();
    return canceled;
}
