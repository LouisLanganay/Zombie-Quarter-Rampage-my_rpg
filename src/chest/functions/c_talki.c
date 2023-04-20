/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** c_talki
*/

#include "rpg.h"

void c_talki(rpg_t *rpg, tiled_object_t *obj)
{
    char *str = get_language(rpg, "to_inspect", RSG);
    draw_interaction_popup(rpg, (sfVector2f){obj->pos.x - 100, obj->pos.y - 15},
        RPK->interact.key, str);

    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue) {
        if (obj->is_trigger == 1 ||
            my_arr_contains(rpg->chests_opened, obj->name)) {
            rpg->narative->str = get_language(rpg, "empty_talki", RSG);
            start_narative_popup(rpg);
            return;
        }
        add_item_to_inventory(20, rpg);
        rpg->chests_opened = add_item_to_arr(rpg->chests_opened, "c_talki");
        obj->is_trigger = 1;
    }
    while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
}
