/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writestr
*/

#include "../../jp.h"

void jp_writestr(int fd, char *str)
{
    write(fd, str, my_strlen(str));
}
