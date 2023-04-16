/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** remove_item_to_inventory
*/

#include "rpg.h"

int remove_item_to_inventory(rpg_t *rpg, int pos)
{
    if (RPI->items[pos] == -1)
        return -1;
    add_item_popup(rpg, RPI->items[pos], REMOVE);
    RPI->items[pos] = -1;
    return 0;
}
