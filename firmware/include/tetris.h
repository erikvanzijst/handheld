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

void materialize(shape_t *dest, volatile fallingbrick_t *brick);
bool fits(fallingbrick_t *brick, const volatile uint16_t *board);
bool move(fallingbrick_t *dest, volatile fallingbrick_t *src, int rot, vertex_t *vector, volatile uint16_t *board);
uint8_t merge(volatile fallingbrick_t *brick, volatile uint16_t *board);
uint16_t get_speed(uint16_t lines);
void pause();
void gameover(const uint16_t * board, uint16_t score, uint32_t hiscore);
void dump_boad(const uint16_t * board);
void dump_row(const uint16_t row);

#endif
