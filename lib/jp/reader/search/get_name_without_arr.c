/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** get_name_without_arr
*/

#include "../../jp.h"

char *get_name_without_arr(char *str)
{
    char *tmp = malloc(sizeof(char) * (name_len(str) - 2));
    int i = 0;

    while (str[i] != '[') {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}
