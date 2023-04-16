/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** remove_itemid_inventory
*/

#include "rpg.h"

int remove_itemid_inventory(rpg_t *rpg, int item_id)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (rpg->player->inventory->items[i] == item_id)
            return remove_item_to_inventory(rpg, i);
    }
    return -1;
}
