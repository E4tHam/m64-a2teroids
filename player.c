
#include "player.h"

#include <stop.h>

#include "patterns.h"
#include "obma_stack.h"
#include "game_state.h"
#include "game.h"

player_t player[2];

const uint8_t chicken_red_pmfa = 1;
const uint8_t chicken_white_pmfa = 2;
const uint8_t chicken_yellow_pmfa = 3;
const uint8_t mouse_black_pmfa = 4;
const uint8_t mouse_magenta_pmfa = 5;
const uint8_t mouse_white_pmfa = 6;
const uint8_t seahorse_magenta_pmfa = 7;
const uint8_t seahorse_yellow_pmfa = 8;

bool players_initialized = 0;

void players_initialize(void) {
    uint8_t i;
    for (i=0; i < 2; i++) {
        // only first time initialize
        if (!players_initialized) {
            player[i].fighter = i;
            player[i].num_obmas = 0;
            player_fighter_set(i, player[i].fighter);
            player[i].score_l = 0;
            player[i].score_u = 0;
        }
        // reset position
        player[i].velocity.x = 0;
        player[i].velocity.y = 0;
        player[i].position.x = ( 64 + (i ? 128 : 0) );
        player[i].position.y = ( 124 );
    }
    players_initialized = true;
}

void player_fighter_set(const uint8_t player_num, const uint8_t select) {

    // start fresh
    player_fighter_remove(player_num);

    switch (select) {
    case PLAYER_SELECT_CHICKEN:
        player[player_num].num_obmas = 3;
        break;
    case PLAYER_SELECT_SEAHORSE:
        player[player_num].num_obmas = 2;
        break;
    case PLAYER_SELECT_MOUSE:
        player[player_num].num_obmas = 3;
        break;
    default:
        player[player_num].num_obmas = 0;
        stop();
    }

    obma_stack_pop( player[player_num].obmas, player[player_num].num_obmas );

    switch (select) {
    case PLAYER_SELECT_CHICKEN:
        OBM[player[player_num].obmas[0]].pattern_config = chicken_red_pmfa;
        OBM[player[player_num].obmas[1]].pattern_config = chicken_white_pmfa;
        OBM[player[player_num].obmas[2]].pattern_config = chicken_yellow_pmfa;
        OBM[player[player_num].obmas[0]].color = RED_C_MASK;
        OBM[player[player_num].obmas[1]].color = WHITE_C_MASK;
        OBM[player[player_num].obmas[2]].color = YELLOW_C_MASK;
        break;
    case PLAYER_SELECT_SEAHORSE:
        OBM[player[player_num].obmas[0]].pattern_config = seahorse_magenta_pmfa;
        OBM[player[player_num].obmas[1]].pattern_config = seahorse_yellow_pmfa;
        OBM[player[player_num].obmas[0]].color = MAGENTA_C_MASK;
        OBM[player[player_num].obmas[1]].color = YELLOW_C_MASK;
        break;
    case PLAYER_SELECT_MOUSE:
        OBM[player[player_num].obmas[0]].pattern_config = mouse_black_pmfa;
        OBM[player[player_num].obmas[1]].pattern_config = mouse_magenta_pmfa;
        OBM[player[player_num].obmas[2]].pattern_config = mouse_white_pmfa;
        OBM[player[player_num].obmas[0]].color = BLACK_C_MASK;
        OBM[player[player_num].obmas[1]].color = MAGENTA_C_MASK;
        OBM[player[player_num].obmas[2]].color = WHITE_C_MASK;
        break;
    default:
        break;
    }
}

void player_fighter_remove(const uint8_t player_num) {
    uint8_t i;
    for (i = 0; i < player[player_num].num_obmas; i++) {
        OBM[player[player_num].obmas[i]].y = 0xff;
    }
    player[player_num].num_obmas = 0;
    obma_stack_push( player[player_num].obmas, player[player_num].num_obmas );
}

void players_draw(void) {
    uint8_t i;
    uint8_t p0_flip, p1_flip;

    if ( (player[0].position.x > player[1].position.x) ^ ((game_state==GAME_STATE_GAME)&&in_grace_period()) ) {
        p0_flip = 0;
        p1_flip = HFLIP_MASK;
    } else {
        p0_flip = HFLIP_MASK;
        p1_flip = 0;
    }

    for (i = 0; i < player[0].num_obmas; i++) {
        OBM[player[0].obmas[i]].x = (player[0].position.x);
        OBM[player[0].obmas[i]].y = (player[0].position.y);
        OBM[player[0].obmas[i]].pattern_config &= ~HFLIP_MASK;
        OBM[player[0].obmas[i]].pattern_config |= p0_flip;
    }
    for (i = 0; i < player[1].num_obmas; i++) {
        OBM[player[1].obmas[i]].x = (player[1].position.x);
        OBM[player[1].obmas[i]].y = (player[1].position.y);
        OBM[player[1].obmas[i]].pattern_config &= ~HFLIP_MASK;
        OBM[player[1].obmas[i]].pattern_config |= p1_flip;
    }
}

void player_score_increment(const uint8_t player_num) {
    if (player[player_num].score_l==9) {
        player[player_num].score_l = 0;
        player[player_num].score_u = (player[player_num].score_u==9) ? 0 : player[player_num].score_u+1;
    } else {
        player[player_num].score_l++;
    }
}
