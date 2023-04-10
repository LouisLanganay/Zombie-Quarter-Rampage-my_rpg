/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_game
*/

#include "rpg.h"

void start_game(rpg_t *rpg, char *save_path)
{
    rpg->game_started = 1;
    load_save(rpg, save_path);
}
