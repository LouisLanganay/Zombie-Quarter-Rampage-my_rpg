/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** arr_len
*/

#include "rpg.h"

int arr_len(char **arr)
{
    int i = 0;

    while (arr[i] != NULL) i++;
    return (i);
}
