/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** my_arrlen
*/

#include "rpg.h"

int my_arrlen(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++);
    return (i);
}
