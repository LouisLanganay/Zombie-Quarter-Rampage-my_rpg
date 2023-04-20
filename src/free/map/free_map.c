/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** free_map
*/

#include "rpg.h"

static void free_map_textures(map_t *map)
{
    for (int i = 0; map->textures[i]; i++)
        sfTexture_destroy(map->textures[i]);
    free(map->textures);
}

void free_map(map_t *tmp)
{
    free_map_textures(tmp);
    free_map_layers(tmp);
    //free_map_npcs(tmp);
    //free_map_tilesets(tmp);
    free(tmp);
}
