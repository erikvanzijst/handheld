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
