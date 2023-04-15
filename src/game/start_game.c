/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_game
*/

#include "rpg.h"

void start_game(rpg_t *rpg, char *save_path)
{
    rpg->game_state = GAME;
    load_save(rpg, save_path);
    fade_sound(rpg, MAIN_THEME_ID, 8);
    rpg->menu_save->active = false;
    rpg->menu_key->active = false;
    rpg->menu->active = false;
}
