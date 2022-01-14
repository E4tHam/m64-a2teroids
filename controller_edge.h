
#ifndef __CONTROLLER_EDGE_H
#define __CONTROLLER_EDGE_H

#include <controller.h>

extern uint8_t
    CONTROLLER_1_PREV,  CONTROLLER_2_PREV,
    CONTROLLER_1_PEDGE, CONTROLLER_2_PEDGE,
    CONTROLLER_1_NEDGE, CONTROLLER_2_NEDGE;

// reset controller edge values
void controller_edge_reset(void);

// update controller edge values
void controller_edge_update(void);

#endif
