/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** c_gaz
*/

#include "rpg.h"

void c_gaz(rpg_t *rpg, tiled_object_t *obj)
{
    sfVector2f pos2 = {obj->pos.x - 70, obj->pos.y - 15};
    char *str = get_language(rpg, "gaz_interact", RSG);
    draw_interaction_popup(rpg, pos2, RPK->interact.key, str);

    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue) {
        if (obj->is_trigger == 1 ||
            my_arr_contains(rpg->chests_opened, obj->name)) {
            rpg->narative->str = get_language(rpg, "empty_gaz", RSG);
            start_narative_popup(rpg);
            return;
        }
        add_item_to_inventory(31, rpg);
        stop_quest(rpg, "jack_quest");
        start_quest(rpg, "jack_friend");
        rpg->chests_opened = add_item_to_arr(rpg->chests_opened, "c_gaz");
        obj->is_trigger = 1;
    }
    while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
}
