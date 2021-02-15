#include <atmel_start_pins.h>
#include <compiler.h>
#include <port.h>
#include <stdint.h>
#include <stdio.h>
#include "sound.h"

bool sound_enabled = true;

typedef struct {
    uint8_t prescalar;          // timer prescalar
    uint16_t period;            // timer period
    int32_t toggle_count;       // total duration
    int32_t toggle_remaining;   // -1 for indefinitely
} tone_t;

typedef struct {
    melody_t *melody;
    /*
     * The next note to be played `(0 <= current_note < .melody->len)`.
     */
    uint16_t current_note;
    int16_t remaining;          // -1 for indefinitely
} running_melody_t;

running_melody_t curr_melody = {
    .melody = NULL,
    .current_note = 0
};
tone_t curr_tone;

/*
 * Starts `curr_melody`'s current note (`curr_melody->current_note`).
 */
void play_next_note() {
    // queue the next tone
    uint16_t wholenote = (60000 * 4) / curr_melody.melody->tempo;
    uint32_t duration = 0;

    int16_t frequency = curr_melody.melody->notes[curr_melody.current_note * 2];
    int16_t divider = curr_melody.melody->notes[curr_melody.current_note * 2 + 1];

    if (divider > 0) {
        // regular note, just proceed
        duration = wholenote / divider;
    }
    else if (divider < 0) {
        // dotted notes are represented with negative durations!
        duration = wholenote / abs(divider);
        duration *= 1.5; // increases the duration in half for dotted notes
    }

    uint8_t prescalar = TC_CLKSEL_DIV1_gc;
    uint32_t period = F_CPU / frequency / 2 - 1;

    if (period > 0xffff) {
        prescalar = TC_CLKSEL_DIV64_gc;
        period = F_CPU / frequency / 2 / 64 - 1;
    }

    if (duration > 0) {
        curr_tone.toggle_count = curr_tone.toggle_remaining = 2 * frequency * duration / 1000;
    } else {
        curr_tone.toggle_count = curr_tone.toggle_remaining = -1;
    }
    TCE0.CTRLA = prescalar;
    TCE0.PER = period;

    // printf("Staring new tone %uHz, %ums\r\n", frequency, duration);
}

void play_melody(melody_t *melody, uint16_t repeat) {
    if (melody->len < 1) {
        printf("WARNING: Ignoring zero-lenth melody\r\n");
    }
    else {
        curr_melody.melody = melody;
        curr_melody.current_note = 0;
        curr_melody.remaining = (repeat == 0 ? -1 : repeat);
        play_next_note();
    }
}

void stop_melody() {
    curr_tone.toggle_remaining = -1;
    TCE0.CTRLA = TC_CLKSEL_OFF_gc;
}

bool is_muted() {
    return !sound_enabled;
}

void mute(bool muted) {
    sound_enabled = !muted;
}

void tone_isr() {
    if (curr_tone.toggle_remaining != 0) {
        if (sound_enabled && curr_tone.toggle_remaining < curr_tone.toggle_count * 0.9) {
            // be quiet for the last 10% of note duration
            BUZZER_toggle_level();
        }
		curr_tone.toggle_remaining--;
    }
    else {
        // queue the next tone
        curr_melody.current_note = (curr_melody.current_note + 1) % curr_melody.melody->len;
        if (curr_melody.current_note == 0 && curr_melody.remaining > 0) {
            curr_melody.remaining--;
            printf("Melody finished (%d loops remaining).\r\n", curr_melody.remaining);
        }
        if (curr_melody.remaining != 0) {
            play_next_note();
        } else {
            printf("Melody loop finished.\r\n");
            stop_melody();
        }
    }
}
