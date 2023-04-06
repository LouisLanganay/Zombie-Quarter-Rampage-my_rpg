/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** my_strndup
*/

#include "rpg.h"

char *my_strndup(const char *str, int n)
{
    char *new_str = malloc(sizeof(char) * (n + 1));
    int i = 0;

    if (new_str == NULL)
        return (NULL);
    for (; i < n && str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return (new_str);
}
