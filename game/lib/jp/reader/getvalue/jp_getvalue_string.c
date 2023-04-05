/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_getvalue_string
*/

#include "../../jp.h"

static int data_name_length(char **str)
{
    int j = 0;

    for (int i = 1; str[0][i] && str[0][i] != '"'; i++) {
        j++;
    }
    return (j);
}

char *jp_getvalue_string(char **str)
{
    int j = 0;
    int my_data_name_length = data_name_length(str);
    char *data_name = malloc(sizeof(char) * (my_data_name_length + 2));

    for (int i = 1; str[0][i] && str[0][i] != '"'; i++) {
        data_name[j] = str[0][i];
        j++;
    }
    data_name[j] = '\0';
    *str += j + 2;
    return (data_name);
}
