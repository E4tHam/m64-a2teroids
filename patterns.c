
#include "patterns.h"
#include "asteroid.h"
#include "player.h"

void load_background_pattern(const pattern_t pattern, const uint8_t pmba) {
    uint8_t i;
    for (i = 0; i < 16; i++)
        PMB[pmba][i] = pattern[i];
}
void load_foreground_pattern(const pattern_t pattern, const uint8_t pmfa) {
    uint8_t i;
    for (i = 0; i < 16; i++)
        PMF[pmfa][i] = pattern[i];
}

void asteroid_load_pattern(void) {
    load_foreground_pattern(white_pattern,asteroid_pmfa);
}

void player_load_patterns( void ) {
    load_foreground_pattern( chicken_red_pattern, chicken_red_pmfa );
    load_foreground_pattern( chicken_white_pattern, chicken_white_pmfa );
    load_foreground_pattern( chicken_yellow_pattern, chicken_yellow_pmfa );
    load_foreground_pattern( mouse_black_pattern, mouse_black_pmfa );
    load_foreground_pattern( mouse_magenta_pattern, mouse_magenta_pmfa );
    load_foreground_pattern( mouse_white_pattern, mouse_white_pmfa );
    load_foreground_pattern( seahorse_magenta_pattern, seahorse_magenta_pmfa );
    load_foreground_pattern( seahorse_yellow_pattern, seahorse_yellow_pmfa );
}

void load_patterns(void) {
    asteroid_load_pattern();
    player_load_patterns();
}
