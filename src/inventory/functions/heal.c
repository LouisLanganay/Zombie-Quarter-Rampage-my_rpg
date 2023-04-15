/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** heal
*/

#include "rpg.h"

void heal(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    int item = RP->inventory->items[RP->inventory->pos];
    if (item == 57 || item == 106)
        RP->hp += 4;
    if (item == 44 || item == 56 || item == 81 || item == 93 || item == 105)
        RP->hp += 8;
    if (item == 82 || item == 94)
        RP->hp += 14;
    if (item == 83 || item == 95)
        RP->hp += 20;
    remove_item_to_inventory(rpg, RP->inventory->pos);
}
