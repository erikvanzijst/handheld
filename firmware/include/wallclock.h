#ifndef WALLCLOCK_INCLUDED
#define WALLCLOCK_INCLUDED

#define TC_INTERVAL 50000

void timer_tick();

/*
 * Returns the current milliseconds since boot.
 */
uint64_t millis();

#endif
