
#include "game.h"

#include "player.h"
#include "asteroids.h"
#include "controllers.h"
#include "game_state.h"
#include "menu.h"

#include <stdlib.h>
#include <arcade_zero_page.h>


bool player0_collision, player1_collision;

void update_player_asteroid_collision( asteroid_t * a ) {
    if (!player0_collision) {
        player0_collision =
            ( OBM[player[0].obmas[0]].x <  OBM[a->obmas[0]].x + ( a->diameter << 3 ) - 1 ) &&
            ( OBM[player[0].obmas[0]].x >= OBM[a->obmas[0]].x - 7 ) &&
            ( OBM[player[0].obmas[0]].y <  OBM[a->obmas[0]].y + ( a->diameter << 3 ) - 1 ) &&
            ( OBM[player[0].obmas[0]].y >= OBM[a->obmas[0]].y - 7 );
    }
    if (!player1_collision) {
        player1_collision =
            ( OBM[player[1].obmas[0]].x <  OBM[a->obmas[0]].x + ( a->diameter << 3 ) - 1 ) &&
            ( OBM[player[1].obmas[0]].x >= OBM[a->obmas[0]].x - 7 ) &&
            ( OBM[player[1].obmas[0]].y <  OBM[a->obmas[0]].y + ( a->diameter << 3 ) - 1 ) &&
            ( OBM[player[1].obmas[0]].y >= OBM[a->obmas[0]].y - 7 );
    }
}

bool get_player_player_collision( void ) {
    return
        ( OBM[player[0].obmas[0]].x <  OBM[player[1].obmas[0]].x + 11 ) &&
        ( OBM[player[0].obmas[0]].x + 11 >= OBM[player[1].obmas[0]].x ) &&
        ( OBM[player[0].obmas[0]].y <  OBM[player[1].obmas[0]].y + 11 ) &&
        ( OBM[player[0].obmas[0]].y + 11 >= OBM[player[1].obmas[0]].y );
}

uint32_t start_frame;

bool in_grace_period(void) {
    return ((FRAME - start_frame) < 48);
}

void game_initialize( void ) {
    uint8_t i, j;

    background_palette = 0;

    asteroid_stack_clear();
    asteroid_stack_initialize();

    for (i = 0; i < 64; i++) {
        asteroid_stack_push( i & 0xf );
    }

    for (i = 0; i < 30; i++)
        for (j = 0; j < 32; j++)
            TXBL[i][j] = 0;

    player0_collision = false;
    player1_collision = false;

    start_frame = FRAME;
}


void game_advance(void) {
    uint8_t i;

    // if collision occurred
    if (player0_collision || player1_collision) {
        // if start was pressed, open menu
        if ((CONTROLLER_1_NEDGE | CONTROLLER_2_NEDGE) & CONTROLLER_START_MASK ) {
            initialized = false;
            game_state = GAME_STATE_MENU;
            if (!player0_collision) p0_score_increment();
            if (!player1_collision) p1_score_increment();
        } else {
            return;
        }
    }

    // move players
    player[0].position.x += player[0].velocity.x;
    player[0].position.y += player[0].velocity.y;
    player[1].position.x += player[1].velocity.x;
    player[1].position.y += player[1].velocity.y;
    players_draw();

    // move asteroids
    asteroid_stack_iterate(asteroid_update);

    // check if collision between player and asteroid
    if ( !in_grace_period() )
        asteroid_stack_iterate(update_player_asteroid_collision);

    // check and handle player player collision
    if (get_player_player_collision()) {
        _swap(&player[0].velocity, &player[1].velocity, sizeof(coordinateS8_t));
        return;
    }

    // accelerate players
    if      (CONTROLLER_1&CONTROLLER_LEFT_MASK)         player[0].velocity.x -= 1;
    else if (CONTROLLER_1&CONTROLLER_RIGHT_MASK)        player[0].velocity.x += 1;
    else if (player[0].velocity.x != 0 && (FRAME&1))    player[0].velocity.x += (player[0].velocity.x<0) ? 1 : -1;
    if      (CONTROLLER_1&CONTROLLER_UP_MASK)           player[0].velocity.y -= 1;
    else if (CONTROLLER_1&CONTROLLER_DOWN_MASK)         player[0].velocity.y += 1;
    else if (player[0].velocity.y != 0 && (FRAME&1))    player[0].velocity.y += (player[0].velocity.y<0) ? 1 : -1;
    if      (CONTROLLER_2&CONTROLLER_LEFT_MASK)         player[1].velocity.x -= 1;
    else if (CONTROLLER_2&CONTROLLER_RIGHT_MASK)        player[1].velocity.x += 1;
    else if (player[1].velocity.x != 0 && (FRAME&1))    player[1].velocity.x += (player[1].velocity.x<0) ? 1 : -1;
    if      (CONTROLLER_2&CONTROLLER_UP_MASK)           player[1].velocity.y -= 1;
    else if (CONTROLLER_2&CONTROLLER_DOWN_MASK)         player[1].velocity.y += 1;
    else if (player[1].velocity.y != 0 && (FRAME&1))    player[1].velocity.y += (player[1].velocity.y<0) ? 1 : -1;

    // clamp velocities
    player[0].velocity.x = Q9_6_clamp(-6,player[0].velocity.x,6);
    player[0].velocity.y = Q9_6_clamp(-6,player[0].velocity.y,6);
    player[1].velocity.x = Q9_6_clamp(-6,player[1].velocity.x,6);
    player[1].velocity.y = Q9_6_clamp(-6,player[1].velocity.y,6);
}
