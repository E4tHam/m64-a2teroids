
#include "asteroid_stack.h"


#include <stdlib.h>

asteroid_t asteroid_stack[ASTEROID_STACK_SIZE];

uint8_t asteroid_stack_start, asteroid_stack_end, asteroid_stack_size;

void asteroid_stack_iterate( void(*f)(asteroid_t * a) ) {
    uint8_t i, k;
    k = 0;
    for (i = 0; i < asteroid_stack_size; i++) {
        f(asteroid_stack + k);
        k++;
        if (k == ASTEROID_STACK_SIZE)
            k = 0;
    }
}

void asteroid_stack_initialize(void) {
    uint8_t i;
    asteroid_stack_size = 0;
    asteroid_stack_start = 0;
    asteroid_stack_end = 0;
    for (i = 0; i < ASTEROID_STACK_SIZE; i++) {
        asteroid_stack[i].velocity.x = 0;
        asteroid_stack[i].velocity.y = 0;
        asteroid_stack[i].num_obmas = 0;
    }
}

void asteroid_stack_clear(void) {
    uint8_t i;
    asteroid_stack_iterate(asteroid_destroy);
    asteroid_stack_size = 0;
    asteroid_stack_start = 0;
    asteroid_stack_end = 0;
}

bool asteroid_stack_push( uint8_t diameter ) {

    union bytes_of_an_int_u {
        sint16_t int16;
        uint8_t byte[2];
    } rand_array[2];

    rand_array[0].int16 = rand();
    rand_array[1].int16 = rand();

    if (ASTEROID_STACK_SIZE == asteroid_stack_size) return 0;

    if (asteroid_create(
        asteroid_stack + asteroid_stack_end,
        rand_array[0].byte[0], rand_array[1].byte[0],
        (sint8_t)(rand_array[0].byte[1]&7)-4, (sint8_t)(rand_array[1].byte[1]&7)-4,
        diameter
    ) == 0)
        return 0;
    asteroid_stack_size++;
    asteroid_stack_end++;
    if (asteroid_stack_end == ASTEROID_STACK_SIZE)
        asteroid_stack_end = 0;
    return 1;
}
