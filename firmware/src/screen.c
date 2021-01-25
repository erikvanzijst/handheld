#include "screen.h"

bool on = true;

void redraw() {
    BATT_set_level(on);
    on = !on;
}
