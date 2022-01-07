
#ifndef __ASTEROIDS_H
#define __ASTEROIDS_H


#include <int.h>

#include "asteroid.h"

#define ASTEROID_STACK_SIZE 64

extern asteroid_t asteroid_stack[ASTEROID_STACK_SIZE];

void asteroid_stack_iterate( void(*f)(asteroid_t * a) );

extern uint8_t asteroid_stack_start, asteroid_stack_end, asteroid_stack_size;

void asteroid_stack_initialize( void );
void asteroid_stack_clear( void );

// uint8_t asteroid_stack_pop( uint8_t * dst, uint8_t dst_size );

uint8_t asteroid_stack_push( uint8_t diameter );

#endif
