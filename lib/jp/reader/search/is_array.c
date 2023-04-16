/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** is_array
*/

#include "../../jp.h"

int is_array(char *name)
{
    int i = 0;

    while (name[i] != '\0' && name[i] != '.') {
        if (name[i] == '[')
            return (1);
        i++;
    }
    return (0);
}
