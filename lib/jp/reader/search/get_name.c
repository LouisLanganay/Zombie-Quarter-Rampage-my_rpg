/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** get_name
*/

#include "../../jp.h"

char *get_name(char *name)
{
    int i = 0;
    char *tmp = malloc(sizeof(char) * (name_len(name) + 1));

    while (name[i] != '.' && name[i] != '\0') {
        tmp[i] = name[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}
