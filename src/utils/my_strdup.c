/*
** EPITECH PROJECT, 2023
** B-PSU-200-REN-2-1-minishell1-louis.langanay
** File description:
** my_strdup
*/

#include "rpg.h"

char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int x = 0;
    for (; str[x]; x++)
        new_str[x] = str[x];
    new_str[x] = '\0';
    return new_str;
}
