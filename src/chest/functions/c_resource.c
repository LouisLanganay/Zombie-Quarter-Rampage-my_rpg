/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** c_resource
*/

#include "rpg.h"

void c_resource(rpg_t *rpg, tiled_object_t *obj)
{
    sfVector2f pos2 = {obj->pos.x - 10, obj->pos.y + 10};
    char *str = get_language(rpg, "resource_interact", RSG);
    draw_interaction_popup(rpg, pos2, RPK->interact.key, str);

    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue) {
        if (my_arr_contains(rpg->chests_opened, obj->name)) {
            rpg->narative->str = get_language(rpg, "empty_resource", RSG);
            start_narative_popup(rpg);
            return;
        }
        add_item_to_inventory(57, rpg);
        add_item_to_inventory(42, rpg);
        add_item_to_inventory(110, rpg);
        rpg->chests_opened = add_item_to_arr(rpg->chests_opened, "c_resources");
        obj->is_trigger = 1;
    }
    while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
}
