
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


#include "main.h"

#include "controllers.h"
#include "game_state.h"
#include "object_stack.h"
#include "patterns.h"

#include "player.h"
#include "menu.h"


void reset(void) {
    controllers_reset();

    initialized = false;
    game_state = GAME_STATE_MENU;

    // load patterns
    obma_stack_initialize();

    player_1_fighter = PLAYER_SELECT_CHICKEN;
    player_2_fighter = PLAYER_SELECT_MOUSE;
    player_scores_reset();

    load_patterns();
}

void do_logic(void) {
    if (!initialized)
        initialize();
    controllers_update();
    advance();
}

void fill_vram(void) { }
