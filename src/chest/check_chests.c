/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_chests
*/

#include "rpg.h"

static void draw_objects(tiled_object_t *tmp, rpg_t *rpg, sfRectangleShape *col)
{
    sfRectangleShape_setPosition(col, (sfVector2f){tmp->pos.x, tmp->pos.y});
    sfRectangleShape_setSize(col, (sfVector2f){tmp->width, tmp->height});
    sfRectangleShape_setFillColor(col, (sfColor){50, 50, 70, 100});
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window, col, NULL);
}

static void open_chest(tiled_object_t *tmp, rpg_t *rpg)
{
    chests_t *interactions = get_chests_array();

    for (int i = 0; interactions[i].name; i++) {
        if (my_strcmp(tmp->name, interactions[i].name) == 0) {
            interactions[i].func(rpg, tmp);
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
            open_chest(tmp, rpg);
        }
        if (rpg->debug)
            draw_objects(tmp, rpg, col);
        tmp = tmp->next;
    }
    sfRectangleShape_destroy(col);
}

void check_chests(player_t *player, map_t *map, rpg_t *rpg)
{
    layer_t *tmp = map->layers;

    if (rpg->player->inventory->is_open == 1)
        return;

    while (tmp) {
        if (my_strcmp(tmp->type, "objectgroup") == 0 &&
            my_strcmp(tmp->name, "chests") == 0)
            check_interactions_objects(tmp, rpg, player);
        tmp = tmp->next;
    }
}
