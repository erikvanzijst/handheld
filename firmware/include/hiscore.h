#ifndef HISCORE_INCLUDED
#define HISCORE_INCLUDED
#include <stdint.h>

/*
 * Compares the specified score to the high score in EEPROM and updates the
 * EEPROM value if it's higher.
 *
 * Returns the new high score value.
 */
uint32_t get_and_set_hiscore(uint32_t score);

#endif
