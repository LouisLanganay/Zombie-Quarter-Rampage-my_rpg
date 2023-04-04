/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** load_map_layers
*/

#include "rpg.h"

static void load_layer_data_tilelayer_properties(
    layer_t *layer,
    parsed_data_t *data
)
{
    parsed_data_t *properties = jp_search(data, "properties");
    char *nb = NULL;
    layer->z_index = 0;
    if (properties == NULL)
        return;
    nb = jp_search(data, "properties[0].value")->value.p_str;
    layer->z_index = atoi(nb);
}

static void load_layer_data_objectgroup(
    layer_t *layer,
    parsed_data_t *data
)
{
    layer->id = jp_search(data, "id")->value.p_int;
    layer->name = jp_search(data, "name")->value.p_str;
    layer->opacity = jp_search(data, "opacity")->value.p_int;
    layer->type = jp_search(data, "type")->value.p_str;
    layer->visible = jp_search(data, "visible")->value.p_bool;
    layer->color = jp_search(data, "color")->value.p_str;
    layer->objects = NULL;
    load_layer_objects(data, layer);
}

static void load_layer_data_tilelayer(
    layer_t *layer,
    parsed_data_t *data,
    map_t *map
)
{
    layer->id = jp_search(data, "id")->value.p_int;
    layer->name = jp_search(data, "name")->value.p_str;
    layer->opacity = jp_search(data, "opacity")->value.p_int;
    layer->type = jp_search(data, "type")->value.p_str;
    layer->visible = jp_search(data, "visible")->value.p_bool;
    layer->width = jp_search(data, "width")->value.p_int;
    layer->height = jp_search(data, "height")->value.p_int;
    layer->tiles_count = layer->width * layer->height;
    layer->pos = malloc(sizeof(pos_t));
    layer->pos->x = jp_search(data, "x")->value.p_int;
    layer->pos->y = jp_search(data, "y")->value.p_int;
    layer->data = load_layer_data_arr(data);
    layer->class = jp_search(data, "class")->value.p_str;
    load_layer_data_tilelayer_properties(layer, data);
    if (layer->visible == b_true)
        layer->sprites = load_layer_sprites(layer, map);
}

static int create_layer(parsed_data_t *tmp_arr, map_t *map)
{
    layer_t *tmp = malloc(sizeof(layer_t));
    if (!tmp)
        return write(2, "Error: malloc failed\n", 21);
    char *layer_type = jp_search(tmp_arr, "type")->value.p_str;

    printf("Load layer %s\n", layer_type);
    if (my_strcmp(layer_type, "objectgroup") == 0)
        load_layer_data_objectgroup(tmp, tmp_arr);
    else if (my_strcmp(layer_type, "tilelayer") == 0)
        load_layer_data_tilelayer(tmp, tmp_arr, map);

    tmp->next = map->layers;
    map->layers = tmp;
    return 0;
}

int load_map_layers(map_t *map, parsed_data_t *data)
{
    parsed_data_t *tmp_arr = jp_search(data, "layers")->value.p_arr;

    while (tmp_arr) {
        create_layer(tmp_arr->value.p_obj, map);
        tmp_arr = tmp_arr->next;
    }
    return 0;
}
