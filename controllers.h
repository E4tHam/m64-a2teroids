
#ifndef __CONTROLLERS_H
#define __CONTROLLERS_H

#include <controller.h>

extern uint8_t
    CONTROLLER_1_PREV,  CONTROLLER_2_PREV,
    CONTROLLER_1_PEDGE, CONTROLLER_2_PEDGE,
    CONTROLLER_1_NEDGE, CONTROLLER_2_NEDGE;

void controllers_reset(void);

void controllers_update(void);

#endif
