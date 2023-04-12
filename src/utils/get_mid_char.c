/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_mid_char
*/

#include "rpg.h"

int get_mid_char(const char *str)
{
    int i = 0;
    int len = 0;

    if (str == NULL)
        return (0);

    for (; str[i] != '\0'; i++)
        len++;
    return (len / 2);
}
