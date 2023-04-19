/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_end_map_down
*/

#include "rpg.h"

void i_end_map_down(rpg_t *rpg, sfVector2f pos)
{
    (void)(pos);
    char *str = get_language(rpg, "to_inspect", RSG);
    if (quest_is_in_progress(rpg, "run_away") == 1) return;
    draw_interaction_popup(rpg, (sfVector2f){pos.x + 90, pos.y + 50},
        RPK->interact.key, str);
    if (sfKeyboard_isKeyPressed(rpg->player->keys->interact.key) == sfTrue) {
        rpg->narative->str = get_language(rpg, "down_map_interact", RSG);
        start_narative_popup(rpg);
    }
}
