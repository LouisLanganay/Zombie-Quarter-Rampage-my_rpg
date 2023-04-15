/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** c_fridge
*/

#include "rpg.h"

void c_fridge(rpg_t *rpg, tiled_object_t *obj)
{
    sfVector2f pos2 = {obj->pos.x - 100, obj->pos.y};
    char *str = get_language(rpg, "fridge_interact", RSG);
    draw_interaction_popup(rpg, pos2, RPK->interact.key, str);

    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue) {
        add_item_to_inventory(64, rpg);
        add_item_to_inventory(66, rpg);
        add_item_to_inventory(54, rpg);
        stop_quest(rpg, "basement_paper");
        obj->is_trigger = 1;
    }
}
