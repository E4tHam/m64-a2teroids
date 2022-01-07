
#include "menu.h"

#include "player.h"
#include "controllers.h"
#include "game_state.h"

#include <vram.h>
#include <arcade_zero_page.h>

#include <stop.h>


const char menu_screen[30][32] = {
"                                ",
"                                ",
"                                ",
"                                ",
"           MAPACHE 64           ",
"            A2TEROID            ",
"                                ",
"                                ",
"                                ",
"                                ",
"      Select your fighter!      ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                ",
"    player 1         player 2   ",
"                                ",
"       00               00      ",
"                                ",
"                                ",
"                                ",
"                                ",
"      Press start to begin      ",
"                                ",
"                                ",
"                                ",
"                                ",
"                                "};



void menu_initialize(void) {
    uint8_t i, j;

    background_palette = 0;

    for (i = 0; i < 64; i++)
        OBM[i].y = 0xff;

    for (i = 0; i < 30; i++)
        for (j = 0; j < 32; j++)
            TXBL[i][j] = 0x80|menu_screen[i][j];

    TXBL[19][7]  += p0_score_u;
    TXBL[19][8]  += p0_score_l;
    TXBL[19][24] += p1_score_u;
    TXBL[19][25] += p1_score_l;

    player_initialize(player_1_fighter,0);
    player_initialize(player_2_fighter,1);
}

void menu_handle_start(void) {
    uint8_t i, j;
    for (i = 0; i < 30; i++)
        for (j = 0; j < 32; j++)
            TXBL[i][j] = 0x00;
    game_state = GAME_STATE_GAME;
    initialized = false;
}

uint8_t get_next_fighter_num(const uint8_t num) {
    return ((num+1) % 3);
}
uint8_t get_prev_fighter_num(uint8_t num) {
    return ((num==0) ? 2 : num-1);
}

void menu_advance(void) {
    if (CONTROLLER_1_PEDGE&CONTROLLER_UP_MASK) {
        player_delete(0);
        do player_1_fighter = get_next_fighter_num(player_1_fighter);
        while (player_1_fighter == player_2_fighter);
        player_initialize(player_1_fighter,0);
    }
    if (CONTROLLER_1_PEDGE&CONTROLLER_DOWN_MASK) {
        player_delete(0);
        do player_1_fighter = get_prev_fighter_num(player_1_fighter);
        while (player_1_fighter == player_2_fighter);
        player_initialize(player_1_fighter,0);
    }
        if (CONTROLLER_2_PEDGE&CONTROLLER_UP_MASK) {
        player_delete(1);
        do player_2_fighter = get_next_fighter_num(player_2_fighter);
        while (player_1_fighter == player_2_fighter);
        player_initialize(player_2_fighter,1);
    }
    if (CONTROLLER_2_PEDGE&CONTROLLER_DOWN_MASK) {
        player_delete(1);
        do player_2_fighter = get_prev_fighter_num(player_2_fighter);
        while (player_1_fighter == player_2_fighter);
        player_initialize(player_2_fighter,1);
    }

    if ((CONTROLLER_1_NEDGE|CONTROLLER_2_NEDGE)&CONTROLLER_START_MASK) {
        menu_handle_start();
    }
    players_draw();
}
