/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writedata_name
*/

#include "../jp.h"

void jp_writedata_name(int fd, parsed_data_t *data, int tab_count)
{
    jp_writetab(fd, tab_count);
    jp_writestr(fd, "\"");
    jp_writestr(fd, data->name);
    jp_writestr(fd, "\": ");
}
