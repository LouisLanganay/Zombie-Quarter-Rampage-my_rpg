/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** my_putchar
*/

#include "rpg.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}
