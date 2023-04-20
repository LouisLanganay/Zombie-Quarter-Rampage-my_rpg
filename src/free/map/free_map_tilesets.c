/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** free_map_tilesets
*/

#include "rpg.h"

static void free_map_tileset(tilesets_t *tmp)
{
    free(tmp->name);
    free(tmp->path);
    free(tmp);
}

void free_map_tilesets(map_t *map)
{
    tilesets_t *tmp = map->tilesets;
    tilesets_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free_map_tileset(tmp);
        tmp = next;
    }
}
