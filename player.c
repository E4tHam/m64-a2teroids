
#include "player.h"

#include <stop.h>

#include "patterns.h"
#include "object_stack.h"
#include "velocity.h"

#define PLAYER_SELECT_CHICKEN   0
#define PLAYER_SELECT_SEAHORSE  1
#define PLAYER_SELECT_MOUSE     2

player_t player[2];

const uint8_t chicken_red_pmfa = 1;
const uint8_t chicken_white_pmfa = 2;
const uint8_t chicken_yellow_pmfa = 3;
const uint8_t mouse_black_pmfa = 4;
const uint8_t mouse_magenta_pmfa = 5;
const uint8_t mouse_white_pmfa = 6;
const uint8_t seahorse_magenta_pmfa = 7;
const uint8_t seahorse_yellow_pmfa = 8;

void player_load_pattern( void ) {
    load_foreground_pattern( chicken_red_pattern, chicken_red_pmfa );
    load_foreground_pattern( chicken_white_pattern, chicken_white_pmfa );
    load_foreground_pattern( chicken_yellow_pattern, chicken_yellow_pmfa );
    load_foreground_pattern( mouse_black_pattern, mouse_black_pmfa );
    load_foreground_pattern( mouse_magenta_pattern, mouse_magenta_pmfa );
    load_foreground_pattern( mouse_white_pattern, mouse_white_pmfa );
    load_foreground_pattern( seahorse_magenta_pattern, seahorse_magenta_pmfa );
    load_foreground_pattern( seahorse_yellow_pattern, seahorse_yellow_pmfa );
}

void player_initialize( const uint8_t select, const uint8_t player_num ) {
    uint8_t i;
    uint8_t x, y;

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

    player_load_pattern();

    obma_stack_pop( player[player_num].obmas, player[player_num].num_obmas );

    x = 64 + 128 * player_num;
    y = 124;

    player[player_num].velocity.x = 0;
    player[player_num].velocity.y = 0;


    switch (select) {
    case PLAYER_SELECT_CHICKEN:
        OBM[player[player_num].obmas[0]].x = x;
        OBM[player[player_num].obmas[1]].x = x;
        OBM[player[player_num].obmas[2]].x = x;
        OBM[player[player_num].obmas[0]].y = 124;
        OBM[player[player_num].obmas[1]].y = 124;
        OBM[player[player_num].obmas[2]].y = 124;
        OBM[player[player_num].obmas[0]].pattern_config = chicken_red_pmfa;
        OBM[player[player_num].obmas[1]].pattern_config = chicken_white_pmfa;
        OBM[player[player_num].obmas[2]].pattern_config = chicken_yellow_pmfa;
        OBM[player[player_num].obmas[0]].color = RED_C_MASK;
        OBM[player[player_num].obmas[1]].color = WHITE_C_MASK;
        OBM[player[player_num].obmas[2]].color = YELLOW_C_MASK;
        break;
    case PLAYER_SELECT_SEAHORSE:
        OBM[player[player_num].obmas[0]].x = x;
        OBM[player[player_num].obmas[1]].x = x;
        OBM[player[player_num].obmas[0]].y = 124;
        OBM[player[player_num].obmas[1]].y = 124;
        OBM[player[player_num].obmas[0]].pattern_config = seahorse_magenta_pmfa;
        OBM[player[player_num].obmas[1]].pattern_config = seahorse_yellow_pmfa;
        OBM[player[player_num].obmas[0]].color = MAGENTA_C_MASK;
        OBM[player[player_num].obmas[1]].color = YELLOW_C_MASK;
        break;
    case PLAYER_SELECT_MOUSE:
        OBM[player[player_num].obmas[0]].x = x;
        OBM[player[player_num].obmas[1]].x = x;
        OBM[player[player_num].obmas[2]].x = x;
        OBM[player[player_num].obmas[0]].y = 124;
        OBM[player[player_num].obmas[1]].y = 124;
        OBM[player[player_num].obmas[2]].y = 124;
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
    if (player_num == 0) {
        for (i = 0; i < player[0].num_obmas; i++)
            OBM[player[0].obmas[i]].pattern_config |= HFLIP_MASK;
    }
}
