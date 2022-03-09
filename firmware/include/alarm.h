#ifndef FIRMWARE_ALARM_H
#define FIRMWARE_ALARM_H

void alarm_ovf_isr();
void alarm_cca_isr();

/*
 * Single, global alarm that can be scheduled with microsecond precision.
 * Only one alarm can be active at any one time and calling `set_alarm`
 * cancels any active alarm.
 *
 * Alarms are not recurring.
 */
void set_alarm(uint64_t micros_from_now, void (*alarm_callback)(void));

/*
 * Cancels any active alarm.
 *
 * Returns true if an alarm was active, false otherwise.
 */
bool clr_alarm();

#endif //FIRMWARE_ALARM_H
