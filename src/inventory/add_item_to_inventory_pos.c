/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** add_item_to_inventory_pos
*/

#include "rpg.h"

int add_item_to_inventory_pos(rpg_t *rpg, int pos, int id)
{
    if (RPI->items[pos] != -1)
        return -1;
    RPI->items[pos] = id;
    return id;
}
