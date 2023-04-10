/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** create_map
*/

#include "rpg.h"

static void init_values(
    map_t *tmp,
    parsed_data_t *data,
    char *json_path,
    rpg_t *rpg
)
{
    tmp->tilesets = NULL;
    load_tilesets(data, tmp);
    tmp->map_path = json_path;
    tmp->map_width = jp_search(data, "width")->value.p_int;
    tmp->map_height = jp_search(data, "height")->value.p_int;
    tmp->tile_width = jp_search(data, "tilewidth")->value.p_int;
    tmp->tile_height = jp_search(data, "tileheight")->value.p_int;
    tmp->textures = load_tiles_textures(tmp);
    tmp->layers = NULL;
    load_map_layers(tmp, data);
    tmp->tiles = NULL;
    load_tiles_colisions(tmp, data);
    init_npcs(tmp, "resources/jsons/npc.json", rpg);
}

int create_map(rpg_t *rpg, char *json_path)
{
    map_t *tmp = malloc(sizeof(map_t));
    if (!tmp)
        return write(2, "Error: malloc failed\n", 21);
    parsed_data_t *data = jp_parse(json_path);

    printf("Create map: %s\n", json_path);

    init_values(tmp, data, json_path, rpg);

    tmp->next = rpg->maps;
    rpg->maps = tmp;
    return 0;
}
