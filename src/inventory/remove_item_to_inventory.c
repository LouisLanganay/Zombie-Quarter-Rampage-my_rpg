/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** remove_item_to_inventory
*/

#include "rpg.h"

int remove_item_to_inventory(rpg_t *rpg, int pos)
{
    if (rpg->player->inventory->items[pos] == -1)
        return -1;
    rpg->player->inventory->items[pos] = -1;
    return 0;
}
