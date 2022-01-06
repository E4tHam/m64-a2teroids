
#ifndef __PLAYER_H
#define __PLAYER_H


#include <vram.h>

#include "velocity.h"

#define PLAYER_SELECT_CHICKEN   0
#define PLAYER_SELECT_SEAHORSE  1
#define PLAYER_SELECT_MOUSE     2

typedef struct player_s {
    velocity16_t velocity;
    uint8_t num_obmas;
    uint8_t obmas[16];
} player_t;

extern player_t player[2];

extern const uint8_t chicken_red_pmfa;
extern const uint8_t chicken_white_pmfa;
extern const uint8_t chicken_yellow_pmfa;
extern const uint8_t mouse_black_pmfa;
extern const uint8_t mouse_magenta_pmfa;
extern const uint8_t mouse_white_pmfa;
extern const uint8_t seahorse_magenta_pmfa;
extern const uint8_t seahorse_yellow_pmfa;

void player_load_pattern(void);

void player_initialize(const uint8_t select, const uint8_t player_num);


#endif
