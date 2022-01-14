
#include "obma_stack.h"

#include <vram.h>

uint8_t obma_stack[OBMA_STACK_SIZE];

uint8_t obma_stack_start, obma_stack_end, obma_stack_size;

void obma_stack_initialize(void) {
    uint8_t i;
    obma_stack_size = OBMA_STACK_SIZE;
    obma_stack_start = 0;
    obma_stack_end = 0;
    for (i = 0; i < OBMA_STACK_SIZE; i++) {
        obma_stack[i] = i;
        OBM[i].y = 0xff;
    }
}

uint8_t obma_stack_pop(uint8_t * dst, uint8_t dst_size) {
    uint8_t i;
    if (obma_stack_size < dst_size) return 0;
    obma_stack_size -= dst_size;
    for (i = 0; i < dst_size; i++) {
        dst[i] = obma_stack[obma_stack_start];
        obma_stack_start++;
        if (obma_stack_start == OBMA_STACK_SIZE)
            obma_stack_start = 0;
    }
    return dst_size;
}

uint8_t obma_stack_push(uint8_t * src, uint8_t src_size) {
    uint8_t i;
    if (( OBMA_STACK_SIZE - obma_stack_size ) < src_size) return 0;
    obma_stack_size += src_size;
    for (i = 0; i < src_size; i++) {
        obma_stack[obma_stack_end] = src[i];
        obma_stack_end++;
        if (obma_stack_end == OBMA_STACK_SIZE)
            obma_stack_end = 0;
    }
    return src_size;
}
