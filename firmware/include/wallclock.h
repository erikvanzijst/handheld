#ifndef WALLCLOCK_INCLUDED
#define WALLCLOCK_INCLUDED

void timer_tick();

/*
 * Returns the current milliseconds since boot.
 */
uint64_t millis();

#endif
