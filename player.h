
#ifndef __PLAYER_H
#define __PLAYER_H


#include <vram.h>

#include "coordinate.h"

#define PLAYER_SPEED    1

#define PLAYER_SELECT_CHICKEN   0
#define PLAYER_SELECT_SEAHORSE  1
#define PLAYER_SELECT_MOUSE     2

typedef struct player_s {
    coordinateS8_t velocity;
    coordinateU8_t position;
    uint8_t num_obmas;
    uint8_t obmas[16];
} player_t;

extern player_t player[2];

extern uint8_t player_1_fighter;
extern uint8_t player_2_fighter;

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

void player_delete(const uint8_t player_num);

void players_draw(void);

extern uint8_t p0_score_u, p0_score_l, p1_score_u, p1_score_l;

void p0_score_increment(void);
void p1_score_increment(void);
void player_scores_reset(void);


#endif
