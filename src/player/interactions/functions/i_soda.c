/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_soda
*/

#include "rpg.h"

void i_soda(rpg_t *rpg, sfVector2f pos)
{
    (void)(pos);
    char *str = get_language(rpg, "to_inspect", RSG);
    draw_interaction_popup(rpg, (sfVector2f){pos.x, pos.y},
        RPK->interact.key, str);
    if (sfKeyboard_isKeyPressed(rpg->player->keys->interact.key) == sfTrue) {
        if (rand() % 10 == 0) {
            gl_play_sound(rpg->glib, PIECE_SOUND_ID);
            add_item_to_inventory(113, rpg);
        }
        rpg->narative->str = get_language(rpg, "soda_interact", RSG);
        start_narative_popup(rpg);
        while (sfKeyboard_isKeyPressed(rpg->player->keys->interact.key)
        == sfTrue) {}
    }
}
