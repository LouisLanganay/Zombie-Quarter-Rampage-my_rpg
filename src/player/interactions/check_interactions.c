/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_interactions
*/

#include "rpg.h"

static void draw_objects(tiled_object_t *tmp, rpg_t *rpg, sfRectangleShape *col)
{
    sfRectangleShape_setPosition(col, (sfVector2f){tmp->pos.x, tmp->pos.y});
    sfRectangleShape_setSize(col, (sfVector2f){tmp->width, tmp->height});
    sfRectangleShape_setFillColor(col, (sfColor){0, 0, 255, 30});
    if (tmp->name[0] == 'c')
        sfRectangleShape_setFillColor(col, (sfColor){231, 155, 96, 30});
    if (tmp->name[0] == 's')
        sfRectangleShape_setFillColor(col, (sfColor){224, 96, 231, 30});
    if (my_strcmp(tmp->name, "s_nature") == 0) return;
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window, col, NULL);
}

static void exe_interaction_functions_entry(
    tiled_object_t *tmp,
    rpg_t *rpg
)
{
    interactions_t *interactions = get_interactions_array();

    for (int i = 0; interactions[i].name; i++) {
        if (my_strcmp(tmp->name, interactions[i].name) == 0) {
            interactions[i].func(rpg, tmp->pos);
            return;
        }
    }
}

static void exe_interaction_functions_exit(
    tiled_object_t *tmp,
    rpg_t *rpg
)
{
    interactions_t *interactions = get_interactions_array();

    if (tmp->is_exit != 1) return;

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
    rpg_t *rpg,
    player_t *player
)
{
    tiled_object_t *tmp = layer->objects;
    sfRectangleShape *col = sfRectangleShape_create();
    while (tmp) {
        if (player->pos.x + player->rect.width / 2 >= tmp->pos.x &&
            player->pos.x + player->rect.width / 2 <= tmp->pos.x + tmp->width &&
            player->pos.y >= tmp->pos.y &&
            player->pos.y <= tmp->pos.y + tmp->height) {
            exe_interaction_functions_entry(tmp, rpg);
            tmp->is_trigger = 1;
            tmp->is_exit = 0;
        } else {
            tmp->is_trigger = 0;
            exe_interaction_functions_exit(tmp, rpg);
            tmp->is_exit = 1;
        }
        if (rpg->debug)
            draw_objects(tmp, rpg, col);
        tmp = tmp->next;
    }
    sfRectangleShape_destroy(col);
}

void check_interactions(player_t *player, map_t *map, rpg_t *rpg)
{
    layer_t *tmp = map->layers;

    if (player->inventory->is_open == 1) return;

    while (tmp) {
        if (my_strcmp(tmp->type, "objectgroup") == 0 &&
            my_strcmp(tmp->name, "chests") != 0
            && my_strcmp(tmp->name, "sounds"))
            check_interactions_objects(tmp, rpg, player);
        tmp = tmp->next;
    }
}
