/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** add_item_to_inventory
*/

#include "rpg.h"

int add_item_to_inventory(int id, rpg_t *rpg)
{
    int i = 0;

    while (rpg->player->inventory->items[i] != -1)
        i++;
    if (i > INVENTORY_SIZE)
        return -1;
    rpg->player->inventory->items[i] = id;
    return id;
}
