#ifndef TETROMINOS_INCLUDED
#define TETROMINOS_INCLUDED

#include <stdint.h>

typedef struct {
    int8_t x, y;
} vertex_t;

typedef struct {
    vertex_t vertex[4];
} shape_t;

typedef struct {
    shape_t shape[4];
} brickdef_t;

extern brickdef_t brickdefs[7];

#endif
