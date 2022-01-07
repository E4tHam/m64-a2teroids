
#ifndef __GAME_STATE_H
#define __GAME_STATE_H

#include <int.h>

#define GAME_STATE_MENU     ((uint8_t)0)
#define GAME_STATE_GAME     ((uint8_t)1)

extern uint8_t game_state;
extern bool initialized;

void initialize(void);
void advance(void);

#endif
