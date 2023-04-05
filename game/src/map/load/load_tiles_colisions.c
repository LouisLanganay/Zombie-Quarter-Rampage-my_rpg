/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** load_tiles_colisions
*/

#include "rpg.h"

static void create_colision(parsed_data_t *tmp_arr, tile_t *tile)
{
    tiled_object_t *tmp = malloc(sizeof(tiled_object_t));
    if (!tmp)
        return;
    tmp->id = jp_search(tmp_arr, "id")->value.p_int;
    tmp->pos = (sfVector2f){
        jp_search(tmp_arr, "x")->value.p_float,
        jp_search(tmp_arr, "y")->value.p_float
    };
    tmp->width = jp_search(tmp_arr, "width")->value.p_float;
    tmp->height = jp_search(tmp_arr, "height")->value.p_float;
    tmp->next = tile->colisions;
    tile->colisions = tmp;
}

static void load_tile_specificity(tile_t *tile, parsed_data_t *data)
{
    parsed_data_t *tmp_arr =
        jp_search(data, "objectgroup.objects")->value.p_arr;

    while (tmp_arr) {
        create_colision(tmp_arr->value.p_obj, tile);
        tmp_arr = tmp_arr->next;
    }
}

static void create_tile(parsed_data_t *tmp_arr, map_t *map, int count)
{
    tile_t *tmp = malloc(sizeof(tile_t));
    if (!tmp)
        return;
    tmp->id = jp_search(tmp_arr, "id")->value.p_int + count;
    printf("Load tile %i:\n", tmp->id);
    tmp->colisions = NULL;
    load_tile_specificity(tmp, tmp_arr);
    tmp->next = map->tiles;
    map->tiles = tmp;
}

void load_tiles_colisions(map_t *map, parsed_data_t *data)
{
    parsed_data_t *tmp = jp_search(data, "tilesets")->value.p_arr;
    parsed_data_t *tmp_arr = NULL;
    int count = 0;

    while (tmp) {
        tmp_arr = jp_search(tmp->value.p_obj, "tiles");
        if (tmp_arr == NULL) {
            count += jp_search(tmp->value.p_obj, "tilecount")->value.p_int;
            tmp = tmp->next;
            continue;
        }
        tmp_arr = tmp_arr->value.p_arr;
        while (tmp_arr) {
            create_tile(tmp_arr->value.p_obj, map, count);
            tmp_arr = tmp_arr->next;
        }
        count += jp_search(tmp->value.p_obj, "tilecount")->value.p_int;
        tmp = tmp->next;
    }
}
