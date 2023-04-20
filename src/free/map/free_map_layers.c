/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** free_map_layers
*/

#include "rpg.h"

static void free_layer(layer_t *tmp)
{
    free(tmp->name);
    free(tmp->type);
    if (tmp->color != NULL)
        free(tmp->color);
    if (tmp->class != NULL)
        free(tmp->class);
    if (tmp->objects != NULL)
        free_layer_objects(tmp->objects);
    if (tmp->sounds != NULL)
        free_layer_objects(tmp->sounds);
    if (tmp->sprites != NULL) {
        for (int i = 0; tmp->sprites[i]; i++)
            sfSprite_destroy(tmp->sprites[i]);
        free(tmp->sprites);
    }
    free(tmp);
}

void free_map_layers(map_t *map)
{
    layer_t *tmp = map->layers;
    layer_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free_layer(tmp);
        tmp = next;
    }
}
