/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writedata
*/

#include "../jp.h"

void jp_writedata(int fd, parsed_data_t *data, int tab_count)
{
    parsed_data_t *tmp = data;
    jp_writestr(fd, "{\n");
    while (tmp->next != NULL) {
        jp_writedata_name(fd, tmp, tab_count);
        jp_writedata_value(fd, tmp, tab_count);
        tmp = tmp->next;
        if (tmp->next != NULL)
            jp_writestr(fd, ",");
        jp_writestr(fd, "\n");
    }
    jp_writetab(fd, tab_count - 1);
    jp_writestr(fd, "}");
}
