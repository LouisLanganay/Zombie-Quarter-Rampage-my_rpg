/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save_player
*/

#include "rpg.h"

void save_player(rpg_t *rpg)
{
    parsed_data_t *data = jp_parse(rpg->save->path);
    parsed_data_t *player = jp_search(data, "player")->value.p_obj;
    jp_search(player, "pos.x")->value.p_int = rpg->player->pos.x;
    jp_search(player, "pos.y")->value.p_int = rpg->player->pos.y;
    jp_search(player, "hp")->value.p_int = rpg->player->hp;
    jp_write(rpg->save->path, data);
}
