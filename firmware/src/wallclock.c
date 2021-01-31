#include <compiler.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "wallclock.h"

uint64_t deci_seconds = 0;  // each tick is 100ms

void timer_tick() {

    deci_seconds += 1;
    if (deci_seconds % 10 == 0) {
        system_tick();
        // printf("seconds: %9lu, time: %x\r\n", millis(), time(NULL));
    }
}

uint64_t millis() {
    uint64_t dc;
    uint64_t ms;

    do {
        dc = deci_seconds;
        ms = dc * 100 + (((TCD0.CNT + (uint32_t)50000) - TCD0.CCA) % 0xffff) / (F_CPU / 64 / 1000);
    } while (dc != deci_seconds);

    return ms;
}
