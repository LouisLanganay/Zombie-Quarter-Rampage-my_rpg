/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** my_arr_contains
*/

#include "rpg.h"

int my_arr_contains(char **arr, char *str)
{
    for (int i = 0; arr[i] != NULL; i++) {
        if (my_strcmp(arr[i], str) == 0)
            return (1);
    }
    return (0);
}
