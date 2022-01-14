
#ifndef __MENU_H
#define __MENU_H

#include <int.h>

// initialize vram and create default players
void menu_initialize(void);

// reset vram and set game_state to game
void menu_handle_start(void);

// increment character
uint8_t get_next_fighter_num(const uint8_t num);
// decrement character
uint8_t get_prev_fighter_num(const uint8_t num);

void menu_advance(void);


#endif
