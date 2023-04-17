/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** remove_item_to_inventory
*/

#include "rpg.h"

int remove_item_to_inventory(rpg_t *rpg, int pos)
{
    if (RPI->items[pos] == 64) {
        rpg->narative->str = get_language(rpg, "destroy_thuna", RSG);
        start_narative_popup(rpg);
        return 0;
    }
    if (RPI->items[pos] == 9) {
        rpg->narative->str = get_language(rpg, "destroy_bag", RSG);
        start_narative_popup(rpg);
        return 0;
    }
    if (RPI->items[pos] == 31) {
        rpg->narative->str = get_language(rpg, "destroy_gaz_mask", RSG);
        start_narative_popup(rpg);
        return 0;
    }
    if (RPI->items[pos] == -1)
        return -1;
    add_item_popup(rpg, RPI->items[pos], REMOVE);
    RPI->items[pos] = -1;
    return 0;
}
