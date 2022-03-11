#ifndef TETRIS_INCLUDED
#define TETRIS_INCLUDED

#include "tetrominos.h"

extern vertex_t down;
extern vertex_t left;
extern vertex_t right;
extern vertex_t identity;

typedef struct {
    uint8_t id;
    uint8_t rotation;
    vertex_t location;
} fallingbrick_t;

extern uint16_t linevalue[];

/*
 * Enters the Tetris main loop. This function does not return until the game
 * exits.
 */
void tetris();

void materialize(shape_t *dest, fallingbrick_t *brick);
bool fits(fallingbrick_t *brick, uint16_t *board);
bool move(fallingbrick_t *dest, fallingbrick_t *src, int rot, vertex_t *vector, uint16_t *board);
void drawboard(uint16_t *board, fallingbrick_t *brick);
uint8_t merge(fallingbrick_t *brick, unsigned int *board);
uint16_t get_speed(uint16_t lines);
void pause();
void gameover(uint16_t score, uint32_t hiscore);

#endif
