
#ifndef __VELOCITY
#define __VELOCITY

#include <int.h>
#include <Q9_6.h>

typedef struct velocity8_s {
    sint8_t x;
    sint8_t y;
} velocity8_t;

typedef struct velocity16_s {
    Q9_6 x;
    Q9_6 y;
} velocity16_t;

#endif
