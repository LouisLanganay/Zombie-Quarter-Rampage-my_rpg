/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** exec_item_func
*/

#include "rpg.h"

void exec_item_func(rpg_t *rpg, int id)
{
    item_func_t *inte = get_items_functions_arr();
    for (long unsigned int x = 0; inte[x].id != -1; x++) {
        if (inte[x].id == id) {
            inte[x].func(rpg);
            return;
        }
    }
}
