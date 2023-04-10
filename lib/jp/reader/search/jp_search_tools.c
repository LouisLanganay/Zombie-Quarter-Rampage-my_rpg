/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_search_tools
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
