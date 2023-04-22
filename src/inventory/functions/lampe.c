/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** lampe
*/

#include "rpg.h"

void lampe(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    if (my_strcmp(rpg->actual_map, "resources/maps/main_map.json") != 0)
        return;
    if (rpg->game_state != GAME)
        return;
    if (rpg->shader->torch_bool == 0)
        rpg->shader->torch_bool = 1;
    else
        rpg->shader->torch_bool = 0;
}
