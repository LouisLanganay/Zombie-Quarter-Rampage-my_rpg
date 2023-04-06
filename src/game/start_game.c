/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_game
*/

#include "rpg.h"

void start_game(rpg_t *rpg)
{
    rpg->game_started = 1;
    load_save(rpg, "resources/save.json");
}
