
// ==================== game.c ==================== //
// Follow this file template to implement your game //
// ================================================ //

#define SIM 1 // change value depending if running simulation or not

// ================================ //
#pragma code-name ("CODE")
#pragma bss-name ("BSS")

#include <int.h>
#include <vram.h>
#include <stop.h>
#include <Q9_6.h>
#include <arcade_zero_page.h>
#include <controller.h>
#include <screen.h>


#include "object_stack.h"
#include "asteroids.h"
#include "player.h"
#include "velocity.h"

#include <stdlib.h>

bool player0_collision, player1_collision;
bool vram_initialized;

void update_player_asteroid_collision( asteroid_t * a ) {
    if (!player0_collision) {
        player0_collision =
            (OBM[player[0].obmas[0]].x <  OBM[a->obmas[0]].x+(a->diameter<<3)-1) &&
            (OBM[player[0].obmas[0]].x >= OBM[a->obmas[0]].x-7) &&
            (OBM[player[0].obmas[0]].y <  OBM[a->obmas[0]].y+(a->diameter<<3)-1) &&
            (OBM[player[0].obmas[0]].y >= OBM[a->obmas[0]].y-7);
    }
    if (!player1_collision) {
        player1_collision =
            (OBM[player[1].obmas[0]].x <  OBM[a->obmas[0]].x+(a->diameter<<3)-1) &&
            (OBM[player[1].obmas[0]].x >= OBM[a->obmas[0]].x-7) &&
            (OBM[player[1].obmas[0]].y <  OBM[a->obmas[0]].y+(a->diameter<<3)-1) &&
            (OBM[player[1].obmas[0]].y >= OBM[a->obmas[0]].y-7);
    }
}

bool get_player_player_collision(void) {
    return
        (OBM[player[0].obmas[0]].x <  OBM[player[1].obmas[0]].x+7) &&
        (OBM[player[0].obmas[0]].x >= OBM[player[1].obmas[0]].x-7) &&
        (OBM[player[0].obmas[0]].y <  OBM[player[1].obmas[0]].y+7) &&
        (OBM[player[0].obmas[0]].y >= OBM[player[1].obmas[0]].y-7);
}

void initialize_vram(void) {
    uint8_t i, j;

    background_palette = 0;

    obma_stack_initialize();

    player_initialize(PLAYER_SELECT_SEAHORSE,0);
    player_initialize(PLAYER_SELECT_MOUSE,1);

    asteroid_load_pattern();

    asteroid_stack_initialize();

    for (i = 0; i < 64; i++ ) {
        // asteroid_stack_push(1);
        asteroid_stack_push(i&0xf);
    }

    for (i = 0; i < 30; i++)
        for (j = 0; j < 32; j++)
            TXBL[i][j] = 0;

    vram_initialized = true;
}

void reset(void) {
    vram_initialized = false;
    player0_collision = false;
    player1_collision = false;
}

void do_logic(void) {
    if (!vram_initialized) initialize_vram();

    asteroid_stack_iterate(asteroid_update);
    asteroid_stack_iterate(update_player_asteroid_collision);

    // if (player0_collision)
    //     stop();

    // if (get_player_player_collision())
    //     _swap(&player[0].velocity, &player[1].velocity, sizeof(velocity16_t));
}

void fill_vram(void) { }
