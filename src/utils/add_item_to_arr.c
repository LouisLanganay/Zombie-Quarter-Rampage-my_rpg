/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** add_item_to_arr
*/

#include "rpg.h"

char **add_item_to_arr(char **arr, char *item)
{
    char **new_arr = malloc(sizeof(char *) * (arr_len(arr) + 2));
    int i = 0;

    while (arr[i] != NULL) {
        new_arr[i] = arr[i];
        i++;
    }
    new_arr[i] = item;
    new_arr[i + 1] = NULL;
    return (new_arr);
}
