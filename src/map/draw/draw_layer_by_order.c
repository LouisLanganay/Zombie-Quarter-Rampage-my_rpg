/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_layer_by_order
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

static void draw_npc_by_order(rpg_t *rpg, int order, map_t *map)
{
    npc_t *tmp = map->npcs;

    while (tmp != NULL) {
        if (order == 0 && (tmp->pos.y + 35) <= rpg->player->pos.y)
            draw_npc(rpg, tmp);
        if (order == 1 && (tmp->pos.y + 35) > rpg->player->pos.y)
            draw_npc(rpg, tmp);
        tmp = tmp->next;
    }
}

static void draw_layer_by_order_0(layer_t *tmp, rpg_t *rpg, map_t *map)
{
    int y = (rpg->player->pos.y + 1) / map->tile_height - 1;
    if (tmp->visible == b_true && my_strcmp(tmp->type, "tilelayer") == 0
    && my_strcmp(tmp->class, "mid") == 0 && tmp->z_index <= y)
        draw_layer(rpg, tmp);
}

static void draw_layer_by_order_1(layer_t *tmp, rpg_t *rpg, map_t *map)
{
    int y = (rpg->player->pos.y - 1) / map->tile_height - 1;
    if (tmp->visible == b_true && my_strcmp(tmp->type, "tilelayer") == 0
    && my_strcmp(tmp->class, "mid") == 0 && tmp->z_index > y)
        draw_layer(rpg, tmp);
}

void draw_layer_by_order(map_t *map, rpg_t *rpg, int order)
{
    (void)(order);
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
        if (order == 0)
            draw_layer_by_order_0(tmp, rpg, map);
        if (order == 1)
            draw_layer_by_order_1(tmp, rpg, map);
    }
    draw_npc_by_order(rpg, order, map);
}
