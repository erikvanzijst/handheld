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
#include <compiler.h>
#include <stdint.h>
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
        ms = dc * 100 + (((TCD0.CNT + (uint32_t)TC_INTERVAL) - TCD0.CCA) % 0xffff) / (F_CPU / 64 / 1000);
    } while (dc != deci_seconds);

    return ms;
}
