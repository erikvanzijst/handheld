#ifndef FONT_INCLUDED
#define FONT_INCLUDED

#include "button.h"

/*
 * Takes an ASCII string `str` and converts it to font glyphs and writes them
 * to `glyphs`.
 *
 * Since each glyph is 5 bytes wide, `glyphs` must be at least 5 times
 * `strlen(str)`.
 *
 * Returns -1 if one or more of the characters in `str` could not be converted.
 * This could be because the font does not cover the entire ASCII set.
 * 
 * Returns 0 on success.
 */
int to_glyphs(uint8_t *glyphs, const char *str);

/*
 * Takes up to 2 strings and scrolls them across the screen in a perpetual
 * loop. String `line1` scroll on the top half of the screen, `line2`
 * scrolls on the bottom half.
 *
 * If only one string needs to be scrolled, pass an empty string for the
 * remaining string. This will scroll the one string across the center of the
 * screen.
 *
 * This function returns either when the specified timeout runs out, or when a
 * key is pressed. In case of the former, NULL is returned, else a pointer to
 * the key that was pressed is returned.
 *
 * If no buttons are pressed, the function returns after `timeout` milliseconds.
 * -1 scrolls indefinitely.
 */
button_t * scroll(const char *line1, const char *line2, long timeout);

int say(char *str);

#endif
