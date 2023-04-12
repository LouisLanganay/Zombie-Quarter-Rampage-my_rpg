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
    sfRectangleShape_setFillColor(col, (sfColor){0, 0, 255, 100});
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window, col, NULL);
}

static void exe_interaction_functions(
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
            exe_interaction_functions(tmp, rpg);
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
    (void)(player);
    while (tmp) {
        if (my_strcmp(tmp->type, "objectgroup") == 0
            && my_strcmp(tmp->name, "sounds") != 0)
            check_interactions_objects(tmp, rpg, player);
        tmp = tmp->next;
    }
}
