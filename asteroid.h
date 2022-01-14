
#ifndef __ASTEROID_H
#define __ASTEROID_H


#include <int.h>

#include "coordinate.h"

typedef struct asteroid_s {
    coordinateS8_t velocity;
    uint8_t num_obmas;
    uint8_t obmas[16];
    uint8_t diameter;
} asteroid_t;

// pattern that all asteroids should use
const extern uint8_t asteroid_pmfa;

// initialize asteroid pattern
void asteroid_load_pattern(void);

// move asteroid
void asteroid_update( asteroid_t * a );

// create asteroid; returns true iff successful
uint8_t asteroid_create(
    asteroid_t * a,
    uint8_t xp, uint8_t yp,
    uint8_t xv, uint8_t yv,
    uint8_t diameter
);

// give back obmas
void asteroid_destroy( asteroid_t * a );

#endif
