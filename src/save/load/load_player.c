/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_player
*/

#include "rpg.h"

static int load_player_inventory(player_t *player, parsed_data_t *data)
{
    data = data->value.p_obj;
    parsed_data_t *arr = jp_search(data, "items")->value.p_arr;

    for (int i = 0; arr; i++) {
        player->inventory->items[i] = arr->value.p_int;
        arr = arr->next;
    }
    return 0;
}

int load_player(player_t *player, parsed_data_t *data)
{
    data = data->value.p_obj;
    player->pos.x = jp_search(data, "pos.x")->value.p_int;
    player->pos.y = jp_search(data, "pos.y")->value.p_int;
    player->hp = jp_search(data, "hp")->value.p_int;
    player->hunger = jp_search(data, "hunger")->value.p_int;
    load_player_inventory(player, jp_search(data, "inventory"));
    return 0;
}
