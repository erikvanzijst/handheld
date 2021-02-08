#include <compiler.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/eeprom.h>

#define FINGERPRINT 54665

typedef struct {
    uint16_t fingerprint;
    uint32_t score;
} hiscore_t;

uint32_t get_and_set_hiscore(uint32_t score) {
    hiscore_t hiscore;

    eeprom_read_block(&hiscore, 0, sizeof(hiscore_t));
    printf("Read hiscore: score: %lu, fingerprint: %u\r\n", hiscore.score, hiscore.fingerprint);

    if (hiscore.fingerprint != FINGERPRINT || hiscore.score < score)
    {
        printf("Updating hiscore to %lu\r\n", score);
        hiscore.fingerprint = FINGERPRINT;
        hiscore.score = score;
        eeprom_update_block(&hiscore, 0, sizeof(hiscore_t));
    }
    return hiscore.score;
}
