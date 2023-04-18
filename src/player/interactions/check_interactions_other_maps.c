/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_interactions_other_maps
*/

#include "rpg.h"

static void exe_interaction_functions_exit(
    tiled_object_t *tmp,
    rpg_t *rpg
)
{
    interactions_t *interactions = get_interactions_array();

    if (tmp->is_exit == 1) return;

    for (int i = 0; interactions[i].name; i++) {
        if (my_strcmp(tmp->name, interactions[i].name) == 0 &&
            interactions[i].on_exit != NULL) {
            interactions[i].on_exit(rpg, tmp->pos);
            return;
        }
    }
}

static void check_interactions_objects(
    layer_t *layer,
    rpg_t *rpg
)
{
    tiled_object_t *tmp = layer->objects;
    while (tmp) {
        if (tmp->is_trigger == 1) {
            tmp->is_trigger = 0;
            exe_interaction_functions_exit(tmp, rpg);
            tmp->is_exit = 1;
        }
        tmp = tmp->next;
    }
}

static void check_interactions_map(map_t *map, rpg_t *rpg)
{
    layer_t *tmp = map->layers;

    while (tmp) {
        if (my_strcmp(tmp->type, "objectgroup") == 0
            && my_strcmp(tmp->name, "sounds") != 0
            && my_strcmp(tmp->name, "NPC") != 0 &&
            my_strcmp(tmp->name, "chests") != 0)
            check_interactions_objects(tmp, rpg);
        tmp = tmp->next;
    }
}

void check_interactions_other_maps(rpg_t *rpg)
{
    map_t *map = rpg->maps;

    while (map != NULL) {
        if (my_strcmp(rpg->actual_map, map->map_path) == 0) {
            map = map->next;
            continue;
        }
        check_interactions_map(map, rpg);
        map = map->next;
    }
}
