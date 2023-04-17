/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_npc_func_arr
*/

#include "rpg.h"

static const dialog_func_t dialog_func[] = {
    { "npc_give_nothing", npc_give_nothing },
    { "npc_give_food", npc_give_food },
    { "jack_start_quest", jack_start_quest },
    { "annia_give_heal", annia_give_heal },
    { "check_if_gaz_mask", check_if_gaz_mask },
    { "remove_mask", remove_mask },
    { "jackfriend_give_heal", jackfriend_give_heal },
    { "jackfriend_give_weapon", jackfriend_give_weapon },
    { NULL, NULL }
};

dialog_func_t *get_npc_func_arr(void)
{
    dialog_func_t *arr = malloc(sizeof(dialog_func_t) *
        (sizeof(dialog_func) / sizeof(dialog_func_t)));
    for (long unsigned int x = 0; x < sizeof(dialog_func) /
        sizeof(dialog_func_t); x++) {
        arr[x].name = dialog_func[x].name;
        arr[x].func = dialog_func[x].func;
    }
    return arr;
}
