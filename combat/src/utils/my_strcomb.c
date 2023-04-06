/*
** EPITECH PROJECT, 2023
** combat
** File description:
** my_strcomb
*/

#include "rpg.h"

char *my_strcomb(char *str1, char *str2)
{
    char *str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    int i = 0;
    int j = 0;

    for (i = 0; str1[i] != '\0'; i++)
        str[i] = str1[i];
    for (j = 0; str2[j] != '\0'; j++)
        str[i + j] = str2[j];
    str[i + j] = '\0';
    return (str);
}