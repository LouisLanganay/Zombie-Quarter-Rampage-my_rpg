/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_items_functions_arr
*/

#include "rpg.h"

item_func_t *get_items_functions_arr(void)
{
    item_func_t inte_array[] = { {33, note},
    {41, food}, {42, food}, {52, food}, {53, food}, {54, food}, {58, food},
    {64, food}, {65, food}, {66, food}, {67, food}, {68, food}, {77, food},
    {78, food}, {79, food}, {80, food}, {89, food}, {91, food}, {92, food},
    {100, food}, {101, food}, {103, food}, {104, food},
    {44, heal}, {56, heal}, {57, heal}, {81, heal}, {82, heal}, {83, heal},
    {93, heal}, {94, heal}, {95, heal}, {105, heal}, {106, heal},
    {20, talkie},
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
