/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writebool
*/

#include "../../jp.h"

void jp_writebool(int fd, bool_t value)
{
    if (value == b_true)
        jp_writestr(fd, "true");
    else if (value == b_false)
        jp_writestr(fd, "false");
}
