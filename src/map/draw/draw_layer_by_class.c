/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_layer_by_class
*/

#include "rpg.h"

static int count_layers(layer_t *layers)
{
    layer_t *tmp = layers;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void draw_layer_by_class(map_t *map, rpg_t *rpg, char *class)
{
    int count = count_layers(map->layers);
    int j = 0;
    layer_t *tmp = map->layers;

    for (int i = 0; i < count; i++) {
        tmp = map->layers;
        j = 0;
        while (j != count - i - 1) {
            tmp = tmp->next;
            j++;
        }
        if (tmp->visible == b_true && my_strcmp(tmp->type, "tilelayer") == 0
        && my_strcmp(tmp->class, class) == 0) {
            draw_layer(rpg, tmp);
        }
    }
}
