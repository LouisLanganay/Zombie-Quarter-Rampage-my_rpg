/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save_combats
*/

#include "rpg.h"

void save_combats(rpg_t *rpg)
{
    parsed_data_t *data = jp_parse(rpg->save->path);
    jp_search(data, "game_timeline.combat1")->value.p_bool =
        rpg->combat_history->i_lauch_combat1_status == 1 ? b_true : b_false;
    jp_search(data, "game_timeline.combat2")->value.p_bool =
        rpg->combat_history->i_lauch_combat2_status == 1 ? b_true : b_false;
    jp_search(data, "game_timeline.combat3")->value.p_bool =
        rpg->combat_history->i_lauch_combat3_status == 1 ? b_true : b_false;
}
