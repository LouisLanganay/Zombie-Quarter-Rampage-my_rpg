/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** name_len
*/

#include "../../jp.h"

int name_len(char *name)
{
    int i = 0;

    while (name[i] != '.' && name[i] != '\0') {
        i++;
    }
    return (i);
}
