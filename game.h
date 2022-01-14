
#ifndef __GAME_H
#define __GAME_H

#include "asteroid.h"

// if player has collided with asteroid
extern bool player0_collision, player1_collision;


// if players are colliding
bool get_player_player_collision( void );

// update player0_collision and player1_collision
void update_player_asteroid_collision(asteroid_t * a);

// fill vram and create asteroids
void game_initialize( void );

// get next frame of game
void game_advance(void);

// if still in grace period
bool in_grace_period(void);


#endif
