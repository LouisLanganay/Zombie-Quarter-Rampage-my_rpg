/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_colisions
*/

#include "rpg.h"

static void check_tile_colisions_draw(rpg_t *rpg, sfRectangleShape *col)
{
    if (rpg->debug != 1) return;
    sfRectangleShape_setFillColor(col, sfRed);
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window, col, NULL);

}

static int check_tile_colisions(
    tile_t *tile,
    rpg_t *rpg,
    map_t *map,
    int index)
{
    tiled_object_t *tmp = tile->colisions;
    sfVector2f pos2;
    sfRectangleShape *col = sfRectangleShape_create();
    sfFloatRect rect1 = sfRectangleShape_getGlobalBounds(RPH);
    sfFloatRect rect2;
    while (tmp) {
        pos2.x = (index % map->map_width) * map->tile_width + tmp->pos.x;
        pos2.y = (index / map->map_width) * map->tile_height + tmp->pos.y;
        sfRectangleShape_setPosition(col, (sfVector2f){pos2.x, pos2.y});
        sfRectangleShape_setSize(col, (sfVector2f){tmp->width, tmp->height});
        rect2 = sfRectangleShape_getGlobalBounds(col);
        check_tile_colisions_draw(rpg, col);
        if (sfFloatRect_intersects(&rect1, &rect2, NULL)) {
            sfRectangleShape_setFillColor(RPH, (sfColor){255, 0, 0, 50});
            return 1;
        }
        tmp = tmp->next;
    }
    sfRectangleShape_destroy(col);
    return 0;
}

static int get_tile_infos(int id, map_t *map, rpg_t *rpg, int index)
{
    tile_t *tmp = map->tiles;
    int r = 0;
    if (map->tiles == NULL)
        return 0;
    while (tmp) {
        if (tmp->id == id)
            r += check_tile_colisions(tmp, rpg, map, index);
        tmp = tmp->next;
    }
    return r;
}

static int check_all_layers(map_t *map, int index, rpg_t *rpg)
{
    layer_t *tmp = map->layers;
    int r = 0;
    while (tmp) {
        if (my_strcmp(tmp->type, "tilelayer") != 0) {
            tmp = tmp->next;
            continue;
        }
        if (quest_is_in_progress(rpg, "run_away") == 1 &&
            my_strcmp(tmp->name, "military") == 0) {
                tmp = tmp->next;
                continue;
            }
        if (tmp->data[index] != 0)
            r += get_tile_infos(tmp->data[index] - 1, map, rpg, index);
        tmp = tmp->next;
    }
    return r;
}

int check_colisions(map_t *map, sfVector2f pos, player_t *player, rpg_t *rpg)
{
    sfRectangleShape_setFillColor(player->hitbox, (sfColor){0, 255, 0, 50});
    int x = pos.x / map->tile_width;
    int y = pos.y / map->tile_height;
    int index = x + y * map->map_width;
    return check_all_layers(map, index, rpg);
}
