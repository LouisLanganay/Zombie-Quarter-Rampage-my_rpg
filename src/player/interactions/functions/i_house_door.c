/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_house_door
*/

#include "rpg.h"

void i_house_door(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        if (my_strcmp(rpg->actual_map, "resources/maps/player_house.json") == 0) {
            rpg->actual_map = "resources/maps/main_map.json";
            rpg->player->pos.x = SPAWN_OUT_HOUSE_X;
            rpg->player->pos.y = SPAWN_OUT_HOUSE_Y;
        } else if (my_strcmp(rpg->actual_map, "resources/maps/main_map.json") == 0) {
            rpg->actual_map = "resources/maps/player_house.json";
            rpg->player->pos.x = SPAWN_INTO_HOUSE_X;
            rpg->player->pos.y = SPAWN_INTO_HOUSE_Y;
        }
    }
    while (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue);
}
