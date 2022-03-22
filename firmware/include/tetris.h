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
