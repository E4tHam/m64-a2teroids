
#ifndef __MENU_H
#define __MENU_H

#include <int.h>

void menu_initialize(void);

void menu_handle_start(void);

uint8_t get_next_fighter_num(const uint8_t num);
uint8_t get_prev_fighter_num(uint8_t num);

void menu_advance(void);


#endif
