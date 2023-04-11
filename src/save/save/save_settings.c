/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save_settings
*/

#include "rpg.h"

static void save_settings_keys(rpg_t *rpg, parsed_data_t *data)
{
    jp_search(data, "up")->value.p_int = RPK->up.key;
    jp_search(data, "down")->value.p_int = RPK->down.key;
    jp_search(data, "left")->value.p_int = RPK->left.key;
    jp_search(data, "right")->value.p_int = RPK->right.key;
    jp_search(data,"interact")->value.p_int = RPK->interact.key;
    jp_search(data,
        "inventory")->value.p_int = RPK->inventory.key;
    jp_search(data, "escape")->value.p_int = RPK->escape.key;
    jp_search(data,
        "choice1")->value.p_int = RPK->choice_one.key;
    jp_search(data,
        "choice2")->value.p_int = RPK->choice_two.key;
}

void save_settings(rpg_t *rpg)
{
    parsed_data_t *data = jp_parse(rpg->save->path);
    save_settings_keys(rpg, jp_search(data, "settings.keys")->value.p_obj);
    jp_search(data, "settings.game_language")
        ->value.p_str = SAVE_GAMELANGUAGE;
    jp_write(rpg->save->path, data);
}
