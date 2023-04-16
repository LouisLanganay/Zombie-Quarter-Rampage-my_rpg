/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writeint
*/

#include "../../jp.h"

static char *handle_neg_nbr(int neg, char *str)
{
    char *str_bis = NULL;

    if (neg == 1) {
        str_bis = malloc(sizeof(char) * (my_strlen(str) + 2));
        str_bis[0] = '-';
        for (int i = 0; str[i] != '\0'; i++) {
            str_bis[i + 1] = str[i];
        }
        str_bis[my_strlen(str) + 1] = '\0';
        free(str);
        return (str_bis);
    }
    return (str);
}

static char *my_int_to_str(int nb)
{
    int nbr_len = my_nbrlen(nb);
    char *str = malloc(sizeof(char) * (nbr_len + 1));
    char *str_bis = malloc(sizeof(char) * (nbr_len + 1));
    int neg = 0;
    int i = 0;
    if (nb < 0) {
        neg = 1;
        nb = nb * -1;
    }
    for (i = 0; nb > 0; i++) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    str[i] = '\0';
    for (int j = 0; str[j] != '\0'; j++)
        str_bis[j] = str[my_strlen(str) - j - 1];
    str_bis[i] = '\0';
    free(str);
    return handle_neg_nbr(neg, str_bis);
}

void jp_writeint(int fd, int nb)
{
    char *str = my_int_to_str(nb);
    write(fd, str, my_strlen(str));
}
