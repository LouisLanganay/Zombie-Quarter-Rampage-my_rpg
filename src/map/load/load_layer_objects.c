/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** load_layer_objects
*/

#include "rpg.h"

static void create_object(parsed_data_t *tmp_arr, layer_t *layer)
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
    tmp->name = jp_search(tmp_arr, "name")->value.p_str;
    tmp->is_exit = 0;
    tmp->is_trigger = 0;
    tmp->next = layer->objects;
    layer->objects = tmp;
}

void load_layer_objects(parsed_data_t *data, layer_t *layer)
{
    parsed_data_t *tmp_arr =
        jp_search(data, "objects")->value.p_arr;

    while (tmp_arr) {
        create_object(tmp_arr->value.p_obj, layer);
        tmp_arr = tmp_arr->next;
    }
}
