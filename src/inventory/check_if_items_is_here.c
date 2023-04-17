/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_if_items_is_here
*/

#include "rpg.h"

int check_if_items_is_here(rpg_t *rpg, int id)
{
    for (int pos = 0; pos < 16; pos++) {
        if (rpg->player->inventory->items[pos] == id)
            return 1;
    }
    return 0;
}
