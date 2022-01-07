#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include "int.h"
#ifndef SIM
// #warning "SIM not defined"
#define SIM 1
#endif

// Import controller values
#if SIM
extern uint8_t CONTROLLER_1;
extern uint8_t CONTROLLER_2;
#else
extern const uint8_t CONTROLLER_1;
extern const uint8_t CONTROLLER_2;
#endif

// Masks for controller values
#define CONTROLLER_A_MASK       ((uint8_t)0x80)
#define CONTROLLER_B_MASK       ((uint8_t)0x40)
#define CONTROLLER_UP_MASK      ((uint8_t)0x08)
#define CONTROLLER_DOWN_MASK    ((uint8_t)0x04)
#define CONTROLLER_LEFT_MASK    ((uint8_t)0x02)
#define CONTROLLER_RIGHT_MASK   ((uint8_t)0x01)
#define CONTROLLER_START_MASK   ((uint8_t)0x10)
#define CONTROLLER_SELECT_MASK  ((uint8_t)0x20)

#endif
