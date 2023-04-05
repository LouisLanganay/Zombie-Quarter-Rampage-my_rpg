/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_dialogue_function
*/

#include "rpg.h"

void check_dialogue_function(rpg_t *rpg, dialog_t *dialogue)
{
    dialog_func_t *func_arr = get_npc_func_arr();

    if (dialogue->function == NULL) return;
    for (int i = 0; func_arr[i].name != NULL; i++) {
        if (my_strcmp(func_arr[i].name, dialogue->function) == 0) {
            func_arr[i].func(rpg);
            return;
        }
    }
}
