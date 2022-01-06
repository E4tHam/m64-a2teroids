
#ifndef __PATTERNS_H
#define __PATTERNS_H


#include <vram.h>

extern const pattern_t white_pattern;
extern const pattern_t white_pattern;
extern const pattern_t chicken_red_pattern;
extern const pattern_t chicken_white_pattern;
extern const pattern_t chicken_yellow_pattern;
extern const pattern_t mouse_black_pattern;
extern const pattern_t mouse_magenta_pattern;
extern const pattern_t mouse_white_pattern;
extern const pattern_t seahorse_magenta_pattern;
extern const pattern_t seahorse_yellow_pattern;


void load_background_pattern(const pattern_t pattern, const uint8_t pmba);
void load_foreground_pattern(const pattern_t pattern, const uint8_t pmfa);


#endif
