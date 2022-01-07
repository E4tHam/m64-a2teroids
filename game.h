
#ifndef __GAME_H
#define __GAME_H

#include "asteroid.h"

extern bool player0_collision, player1_collision;


bool get_player_player_collision( void );

void update_player_asteroid_collision(asteroid_t * a);

void game_initialize( void );

void game_advance(void);

bool in_grace_period(void);


#endif
