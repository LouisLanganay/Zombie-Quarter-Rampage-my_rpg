/*
** EPITECH PROJECT, 2022
** task02
** File description:
** task02
*/

#include "rpg.h"

static int my_putchar_print(char const *str, int i)
{
    return my_putchar(str[i]);
}

/**
 * @brief Print a string of characters
 *
 * @param str Our string of characters
 * @param precision Our numbers of char we want to print
 * @return int Number of characters printed
 */
int my_putstr(char const *str, int precision)
{
    int count = 0;
    if (precision < 0)
        for (int i = 0; str[i] != '\0'; i++)
            count += my_putchar_print(str, i);
    else
        for (int i = 0; str[i] != '\0' && i < precision; i++)
            count += my_putchar_print(str, i);
    return (count);
}
