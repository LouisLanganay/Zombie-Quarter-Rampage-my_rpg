/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_lauch_combat
*/

#include "rpg.h"

void i_lauch_combat(rpg_t *rpg, sfVector2f pos)
{
    char *str = get_language(rpg, "door_key_interact", RSG);
    draw_interaction_popup(rpg, (sfVector2f){pos.x - 60, pos.y - 15},
        RPK->interact.key, str);
    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue) {
        while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
        if (check_if_items_is_here(rpg, 110) == 0) {
            rpg->narative->str = get_language(rpg, "door_key_narative", RSG);
            start_narative_popup(rpg);
        } else {
            rpg->combat_history->i_lauch_combat1_status = 1;
            remove_itemid_inventory(rpg, 110, 1);
            combat(rpg);
        }
    }
}
