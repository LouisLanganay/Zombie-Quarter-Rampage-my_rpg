/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_player
*/

#include "rpg.h"

int load_player(player_t *player, parsed_data_t *data)
{
    data = data->value.p_obj;
    player->pos.x = jp_search(data, "pos.x")->value.p_int;
    player->pos.y = jp_search(data, "pos.y")->value.p_int;
    player->hp = jp_search(data, "hp")->value.p_int;
    return 0;
}
