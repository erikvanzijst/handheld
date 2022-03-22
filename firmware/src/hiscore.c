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
