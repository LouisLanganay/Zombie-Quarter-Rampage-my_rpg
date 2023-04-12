/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_end_map_top
*/

#include "rpg.h"

void i_end_map_top(rpg_t *rpg, sfVector2f pos)
{
    (void)(pos);
    char *str = get_language(rpg, "to_inspect", RSG);
    draw_interaction_popup(rpg, (sfVector2f){pos.x, pos.y + 15},
        RPK->interact.key, str);
    if (sfKeyboard_isKeyPressed(rpg->player->keys->interact.key) == sfTrue) {
        rpg->narative->str = get_language(rpg, "top_map_interact", RSG);
        start_narative_popup(rpg);
    }
}
