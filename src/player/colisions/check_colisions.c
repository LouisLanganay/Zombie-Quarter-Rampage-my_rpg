/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_colisions
*/

#include "rpg.h"

static int check_tile_colisions(
    tile_t *tile,
    player_t *player,
    map_t *map,
    int index)
{
    tiled_object_t *tmp = tile->colisions;
    sfVector2f pos2;
    sfRectangleShape *col = sfRectangleShape_create();
    sfFloatRect rect1 = sfRectangleShape_getGlobalBounds(player->hitbox);
    sfFloatRect rect2;
    while (tmp) {
        pos2.x = (index % map->map_width) * map->tile_width + tmp->pos.x;
        pos2.y = (index / map->map_width) * map->tile_height + tmp->pos.y;
        sfRectangleShape_setPosition(col, (sfVector2f){pos2.x, pos2.y});
        sfRectangleShape_setSize(col, (sfVector2f){tmp->width, tmp->height});
        sfRectangleShape_setFillColor(col, sfRed);
        rect2 = sfRectangleShape_getGlobalBounds(col);
        if (sfFloatRect_intersects(&rect1, &rect2, NULL)) {
            sfRectangleShape_setFillColor(player->hitbox, sfRed);
            return 1;
        }
        tmp = tmp->next;
    }
    sfRectangleShape_destroy(col);
    return 0;
}

static int get_tile_infos(int id, map_t *map, player_t *player, int index)
{
    tile_t *tmp = map->tiles;
    int r = 0;
    if (map->tiles == NULL)
        return 0;
    while (tmp) {
        if (tmp->id == id)
            r += check_tile_colisions(tmp, player, map, index);
        tmp = tmp->next;
    }
    return r;
}

static int check_all_layers(map_t *map, int index, player_t *player)
{
    layer_t *tmp = map->layers;
    int r = 0;
    while (tmp) {
        if (my_strcmp(tmp->type, "tilelayer") != 0) {
            tmp = tmp->next;
            continue;
        }
        if (tmp->data[index] != 0)
            r += get_tile_infos(tmp->data[index] - 1, map, player, index);
        tmp = tmp->next;
    }
    return r;
}

int check_colisions(map_t *map, sfVector2f pos, player_t *player, rpg_t *rpg)
{
    (void)(rpg);
    sfRectangleShape_setFillColor(player->hitbox, sfGreen);
    int x = pos.x / map->tile_width;
    int y = pos.y / map->tile_height;
    int index = x + y * map->map_width;
    return check_all_layers(map, index, player);
}
