/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_game_timeline
*/

#include "rpg.h"

int load_game_timeline(rpg_t *rpg, parsed_data_t *data)
{
    data = data->value.p_obj;
    RP->soda = jp_search(data, "soda")->value.p_int;
    return (0);
}
