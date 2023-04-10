/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writeint
*/

#include "../../jp.h"

static char *my_int_to_str(int nb)
{
    int nbr_len = my_nbrlen(nb);
    char *str = malloc(sizeof(char) * (nbr_len + 1));
    char *str_bis = malloc(sizeof(char) * (nbr_len + 1));
    for (int i = 0; i < nbr_len; i++) {
        str[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    for (int i = 0 ; i < nbr_len ; i++)
        str_bis[i] = str[i];
    for (int x = 0 ; x < nbr_len ; x++)
        str[x] = str_bis[(nbr_len - 1 - x)];
    str[nbr_len] = '\0';
    free(str_bis);
    return str;
}

void jp_writeint(int fd, int nb)
{
    char *str = my_int_to_str(nb);
    write(fd, str, my_strlen(str));
}
