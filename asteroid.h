
#ifndef __ASTEROID_H
#define __ASTEROID_H


#include <int.h>

#include "velocity.h"

typedef struct asteroid_s {
    velocity8_t velocity;
    uint8_t num_obmas;
    uint8_t obmas[16];
    uint8_t diameter;
} asteroid_t;

const extern uint8_t asteroid_pmfa;

void asteroid_load_pattern(void);

void asteroid_update( asteroid_t * a );

uint8_t asteroid_create(
    asteroid_t * a,
    uint8_t xp, uint8_t yp,
    uint8_t xv, uint8_t yv,
    uint8_t diameter
);

void asteroid_destroy( asteroid_t * a );

#endif
