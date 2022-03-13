#ifndef UTIL_INCLUDED
#define UTIL_INCLUDED

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

/*
 * Like stdlib's rand(), but with an upper bound (exclusive). Returns a random
 * value < upper_bound.
 *
 * upper_bound must be <= stdlib:RAND_MAX (0x7fff).
 */
int rand_under(int upper_bound);

#endif
