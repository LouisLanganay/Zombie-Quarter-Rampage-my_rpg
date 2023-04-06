/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_settings
*/

#include "rpg.h"

static void load_settings_key(rpg_t *rpg, parsed_data_t *data)
{
    RPK->up.key = jp_search(data, "up")->value.p_int;
    RPK->down.key = jp_search(data, "down")->value.p_int;
    RPK->left.key = jp_search(data, "left")->value.p_int;
    RPK->right.key = jp_search(data, "right")->value.p_int;
    RPK->interact.key = jp_search(data,"interact")->value.p_int;
    RPK->inventory.key = jp_search(data,
        "inventory")->value.p_int;
    RPK->escape.key = jp_search(data, "escape")->value.p_int;
    RPK->choice_one.key = jp_search(data,
        "choice1")->value.p_int;
    RPK->choice_two.key = jp_search(data,
        "choice2")->value.p_int;
}

int load_settings(rpg_t *rpg, parsed_data_t *data)
{
    data = data->value.p_obj;
    rpg->settings->game_language = GET_SAVE_GAMELANGUAGE;
    load_settings_key(rpg, jp_search(data, "keys")->value.p_obj);
    return (0);
}
