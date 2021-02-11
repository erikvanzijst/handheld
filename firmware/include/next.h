#ifndef NEXT_INCLUDED
#define NEXT_INCLUDED

void initialize_upcoming();

/**
 * Draws the list of upcoming tetrominos on the right side of the screen.
 */
void draw_upcoming();

/**
 * Returns the id of the next tetromino. This also advances the upcoming list
 * and generates a new random tetromino at the end.
 */
uint8_t take_upcoming();

#endif
