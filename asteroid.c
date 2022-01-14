
#include "asteroid.h"

#include "obma_stack.h"
#include "patterns.h"

#include <stdlib.h>

const uint8_t asteroid_pmfa = 0;

void asteroid_update( asteroid_t * a ) {
    uint8_t i;
    for (i = 0; i < a->num_obmas; i++) {
        OBM[a->obmas[i]].x += a->velocity.x;
        OBM[a->obmas[i]].y += a->velocity.y;
    }
}

uint8_t asteroid_create(
    asteroid_t * a,
    uint8_t xp, uint8_t yp,
    uint8_t xv, uint8_t yv,
    uint8_t diameter
) {
    uint8_t i, j, k;
    uint8_t area = diameter * diameter;
    uint8_t color;
    if (diameter > 4) return 0;
    if (obma_stack_pop( a->obmas, area ) == 0) return 0;
    color = (rand()&7);
    if (color == BLACK_C_MASK) color = WHITE_C_MASK;
    a->num_obmas = area;
    a->diameter = diameter;
    a->velocity.x = xv;
    a->velocity.y = yv;
    k = 0;
    for (i = 0; i < diameter; i++) {
        for (j = 0; j < diameter; j++) {
            OBM[a->obmas[k]].x = xp + j * 8;
            OBM[a->obmas[k]].y = yp + i * 8;
            OBM[a->obmas[k]].color = color;

            OBM[a->obmas[k]].pattern_config = asteroid_pmfa;
            k++;
        }
    }
    return 1;
}

void asteroid_destroy( asteroid_t * a ) {
    uint8_t i;
    obma_stack_push( a->obmas, a->num_obmas );
    a->velocity.x = 0;
    a->velocity.y = 0;
    for (i = 0; i < a->num_obmas; i++) {
        OBM[a->obmas[i]].y = 0xff;
    }
}
