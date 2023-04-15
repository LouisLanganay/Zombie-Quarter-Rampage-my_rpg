/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** food
*/

#include "rpg.h"

void food(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    int item = RP->inventory->items[RP->inventory->pos];
    if (item == 41 || item == 58 || item == 66 || item == 67 || item == 78 ||
        item == 89 || item == 101)
        RP->hunger += 4;
    if (item == 42 || item == 53 || item == 64 || item == 65 || item == 68 ||
        item == 77 || item == 91 || item == 100 || item == 103)
        RP->hunger += 8;
    if (item == 52 || item == 54 || item == 79 || item == 92 || item == 104)
        RP->hunger += 14;
    if (item == 80)
        RP->hunger += 20;
    remove_item_to_inventory(rpg, RP->inventory->pos);
}
