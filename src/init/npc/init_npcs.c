/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_npcs
*/

#include "rpg.h"

static void init_npc_interaction(npc_t *npc, map_t *map)
{
    layer_t *layer = map->layers;
    tiled_object_t *tmp = malloc(sizeof(tiled_object_t));

    while (layer != NULL) {
        if (my_strcmp(layer->name, "NPC") == 0) {
            tmp->id = 0;
            tmp->pos = (sfVector2f){npc->pos.x - 42, npc->pos.y - 10};
            tmp->width = 100;
            tmp->height = 100;
            tmp->name = my_strdup(npc->name);
            tmp->is_exit = 0;
            tmp->is_trigger = 0;
            tmp->next = layer->objects;
            layer->objects = tmp;
            return;
        }
        layer = layer->next;
    }
}

static void init_npc_sprite(npc_t *npc)
{
    npc->texture = sfTexture_createFromFile(npc->texture_path, NULL);
    npc->sprite = sfSprite_create();
    sfSprite_setTexture(npc->sprite, npc->texture, sfTrue);
    npc->rect = (sfIntRect){0, 0, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT};
    npc->rect.left = npc->rect.width * 4;
    sfSprite_setTextureRect(npc->sprite, npc->rect);
    sfSprite_setPosition(npc->sprite, npc->pos);
}

static void add_npc_to_linked_list(map_t *map, parsed_data_t *data, rpg_t *rpg)
{
    npc_t *npc = malloc(sizeof(npc_t));
    npc->name = my_strdup(jp_search(data, "name")->value.p_str);
    npc->clock = sfClock_create();
    npc->pos.x = jp_search(data, "pos.x")->value.p_int;
    npc->pos.y = jp_search(data, "pos.y")->value.p_int;
    npc->one_time = jp_search(data, "one_time")->value.p_bool;
    if (jp_search(data, "default_dialog")->type != p_null)
        npc->default_dialog = my_strdup(jp_search(data,
            "default_dialog")->value.p_str);
    else
        npc->default_dialog = NULL;
    npc->texture_path = my_strdup(jp_search(data, "texture_path")->value.p_str);
    init_npc_sprite(npc);
    init_npc_dialogs(npc, jp_search(data, "dialogues")->value.p_arr, rpg);
    init_npc_interaction(npc, map);

    npc->next = map->npcs;
    map->npcs = npc;
}

void init_npcs(map_t *map, char *path, rpg_t *rpg)
{
    parsed_data_t *data = jp_parse(path);
    map->npcs = NULL;

    while (data->next != NULL) {
        if (my_strcmp(jp_search(data->value.p_obj,
            "map")->value.p_str, map->map_path) == 0)
            add_npc_to_linked_list(map, data->value.p_obj, rpg);
        data = data->next;
    }
}
