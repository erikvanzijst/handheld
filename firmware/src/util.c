#include <stdint.h>
#include <stdlib.h>
#include "../include/util.h"

int rand_under(int upper_bound) {
    upper_bound--;
    int v = upper_bound;
    uint8_t bm = 0xfe;

    while (v >>= 1) {
        bm <<= 1;
    }
    bm = ~bm;

    while ((v = (rand() & bm)) > min(upper_bound, RAND_MAX));
    return v;
}
