
#ifndef __ASTEROID_STACK_H
#define __ASTEROID_STACK_H


#include <int.h>

#include "asteroid.h"

#define ASTEROID_STACK_SIZE 64

extern asteroid_t asteroid_stack[ASTEROID_STACK_SIZE];
extern uint8_t asteroid_stack_start, asteroid_stack_end, asteroid_stack_size;

// run f(a) on every asteroid in stack
void asteroid_stack_iterate( void(*f)(asteroid_t * a) );

// initialize and clear asteroid stack
void asteroid_stack_initialize( void );
// delete all asteroids and reset stack
void asteroid_stack_clear( void );

// create random asteroid by diameter; returns true iff successful
bool asteroid_stack_push( uint8_t diameter );

#endif
