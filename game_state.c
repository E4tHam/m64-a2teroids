
#include "game_state.h"

#include <int.h>

#include "menu.h"
#include "game.h"

uint8_t game_state;

bool initialized;

void initialize(void) {
    switch (game_state) {
    case GAME_STATE_MENU:
        menu_initialize(); break;
    case GAME_STATE_GAME:
        game_initialize(); break;
    default:
        break;
    }
    initialized = true;
}

void advance(void) {
    switch (game_state) {
    case GAME_STATE_MENU:
        menu_advance(); break;
    case GAME_STATE_GAME:
        game_advance(); break;
    default:
        break;
    }
}
