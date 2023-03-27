/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_skipspaces
*/

#include "../jp.h"

void jp_skipspaces(char **str)
{
    for (; (**str == ' ' || **str == '\t' || **str == '\n') &&
        **str; *str += 1);
}
