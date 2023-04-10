/*
** EPITECH PROJECT, 2023
** B-PSU-200-REN-2-1-minishell2-louis.langanay
** File description:
** my_strcat_malloc
*/

#include "rpg.h"
#include <stdlib.h>

char *my_strcat_malloc(char *dest, char const *src)
{
    int destlen = my_strlen(dest);
    int i = 0;
    char *new = malloc(sizeof(char) * (destlen + my_strlen(src) + 1));
    while (dest[i] != '\0') {
        new[i] = dest[i];
        i++;
    }
    int j = 0;
    while (src[j] != '\0') {
        new[i] = src[j];
        i++;
        j++;
    }
    new[i] = '\0';
    return new;
}
