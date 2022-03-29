
#ifndef __PLAYER_H
#define __PLAYER_H


#include <vram.h>

#include "coordinate.h"

#define PLAYER_ACCEL        1
#define PLAYER_MAX_SPEED    6

#define PLAYER_SELECT_CHICKEN   0
#define PLAYER_SELECT_SEAHORSE  1
#define PLAYER_SELECT_MOUSE     2

typedef struct player_s {
    coordinateS8_t velocity;
    coordinateU8_t position;
    uint8_t num_obmas;
    uint8_t obmas[16];
    uint8_t fighter;
    uint8_t score_l, score_u;
} player_t;

// players
extern player_t player[2];

extern const uint8_t chicken_red_pmfa;
extern const uint8_t chicken_white_pmfa;
extern const uint8_t chicken_yellow_pmfa;
extern const uint8_t mouse_black_pmfa;
extern const uint8_t mouse_magenta_pmfa;
extern const uint8_t mouse_white_pmfa;
extern const uint8_t seahorse_magenta_pmfa;
extern const uint8_t seahorse_yellow_pmfa;

// load player patterns
void player_load_patterns(void);

// initialize players
void players_initialize(void);

// reserve player objects
void player_fighter_set(const uint8_t player_num, const uint8_t select);
// give up player objects
void player_fighter_remove(const uint8_t player_num);

// copy players to vram
void players_draw(void);

// increment score of player
void player_score_increment(const uint8_t player_num);


#endif
