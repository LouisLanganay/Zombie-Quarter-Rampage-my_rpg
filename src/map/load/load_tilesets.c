/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** load_tilesets
*/

#include "rpg.h"

static char *init_value_path(char *path_file)
{
    char *folder_path = "resources/maps/";
    char *path = malloc(sizeof(char) *
        (my_strlen(path_file) + my_strlen(folder_path) + 1));
    my_strcpy(path, folder_path);
    my_strcat(path, path_file);
    return path;
}

static void create_tileset(parsed_data_t *tmp_arr, map_t *map)
{
    tilesets_t *tmp = malloc(sizeof(tilesets_t));

    printf("Load tileset %s\n",
        jp_search(tmp_arr, "name")->value.p_str);
    tmp->name = jp_search(tmp_arr, "name")->value.p_str;
    tmp->path = init_value_path(jp_search(tmp_arr, "image")->value.p_str);
    tmp->width = jp_search(tmp_arr, "imagewidth")->value.p_int;
    tmp->height = jp_search(tmp_arr, "imageheight")->value.p_int;
    tmp->tile_count = jp_search(tmp_arr, "tilecount")->value.p_int;

    tmp->next = map->tilesets;
    map->tilesets = tmp;
}

static void reverse_linked_list_tilesets(map_t *map)
{
    tilesets_t *prev = NULL;
    tilesets_t *current = map->tilesets;
    tilesets_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    map->tilesets = prev;
}

void load_tilesets(parsed_data_t *data, map_t *map)
{
    parsed_data_t *tmp_arr = jp_search(data, "tilesets")->value.p_arr;
    printf("Load TILESETS\n");
    while (tmp_arr) {
        create_tileset(tmp_arr->value.p_obj, map);
        tmp_arr = tmp_arr->next;
    }
    reverse_linked_list_tilesets(map);
}
