/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save_game
*/

#include "rpg.h"

void save_game(rpg_t *rpg)
{
    parsed_data_t *data = jp_parse(rpg->save->path);
    parsed_data_t *game = jp_search(data, "game")->value.p_obj;

    jp_search(game, "actual_map")->value.p_str = rpg->actual_map;
    jp_write(rpg->save->path, data);
}
