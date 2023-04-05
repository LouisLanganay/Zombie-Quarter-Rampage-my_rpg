/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_maps
*/

#include "rpg.h"

void load_maps(rpg_t *rpg)
{
    create_map(rpg, "resources/maps/main_map.json");
    create_map(rpg, "resources/maps/player_house.json");
    rpg->maps_loaded = 1;
}
