/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** free_map_tiles
*/

#include "rpg.h"

static void free_map_tile(tile_t *tmp)
{
    free_layer_objects(tmp->colisions);
    free(tmp);
}

void free_map_tiles(map_t *map)
{
    tile_t *tmp = map->tiles;
    tile_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free_map_tile(tmp);
        tmp = next;
    }
}