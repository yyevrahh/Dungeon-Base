#ifndef PLAYER_PATHS_H
#define PLAYER_PATHS_H

#include <stdbool.h>

#define STAT_P "player/stats.txt"
#define ITEMS_P "player/items.txt"

void ensure_player_dir();
bool check_p_exists(const char *p_file);
void init_player();
void see_stats();
int get_health();
int get_mana();
int get_lvl();
int get_exp();
int get_intuition();

#endif