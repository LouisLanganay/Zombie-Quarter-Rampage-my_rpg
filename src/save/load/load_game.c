/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_game
*/

#include "rpg.h"

int load_game(rpg_t *rpg, parsed_data_t *data)
{
    data = data->value.p_obj;
    rpg->actual_map = my_strdup(jp_search(data, "actual_map")->value.p_str);
    return (0);
}
