/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_map
*/

#include "rpg.h"

map_t *get_map(rpg_t *rpg, char *map_path)
{
    map_t *map = rpg->maps;

    while (map != NULL) {
        if (my_strcmp(map->map_path, map_path) == 0)
            return (map);
        map = map->next;
    }
    return (NULL);
}
