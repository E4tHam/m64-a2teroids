
#ifndef __OBMA_STACK_H
#define __OBMA_STACK_H


#include <int.h>

#define OBMA_STACK_SIZE 64

extern uint8_t obma_stack[OBMA_STACK_SIZE];

extern uint8_t obma_stack_start, obma_stack_end, obma_stack_size;

void obma_stack_initialize( void );

uint8_t obma_stack_pop( uint8_t * dst, uint8_t dst_size );

uint8_t obma_stack_push( uint8_t * src, uint8_t src_size );

#endif
