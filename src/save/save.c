/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save
*/

#include "rpg.h"

void save(rpg_t *rpg)
{
    save_settings(rpg);
    save_game(rpg);
    save_player(rpg);
}
