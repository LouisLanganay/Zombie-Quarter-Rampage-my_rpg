/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_combats
*/

#include "rpg.h"

int load_combats(rpg_t *rpg, parsed_data_t *data)
{
    data = data->value.p_obj;
    rpg->combat_history->i_lauch_combat1_status = jp_search(data,
        "combat1")->value.p_bool == b_true ? 1 : 0;
    rpg->combat_history->i_lauch_combat2_status = jp_search(data,
        "combat2")->value.p_bool == b_true ? 1 : 0;
    rpg->combat_history->i_lauch_combat3_status = jp_search(data,
        "combat3")->value.p_bool == b_true ? 1 : 0;
    return (0);
}
