/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_items_functions_arr
*/

#include "rpg.h"

item_func_t *get_items_functions_arr(void)
{
    item_func_t inte_array[] = {
        { 106, bandage },
        { -1, NULL }
    };
    item_func_t *inte = malloc(sizeof(item_func_t) *
        (sizeof(inte_array) / sizeof(item_func_t)));
    for (long unsigned int x = 0; x < sizeof(inte_array) /
        sizeof(item_func_t); x++) {
        inte[x].id = inte_array[x].id;
        inte[x].func = inte_array[x].func;
    }
    return inte;
}
