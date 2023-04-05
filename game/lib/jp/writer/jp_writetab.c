/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writetab
*/

#include "../jp.h"

void jp_writetab(int fd, int tab_count)
{
    for (int i = 0; i < tab_count; i++)
        jp_writestr(fd, "\t");
}
