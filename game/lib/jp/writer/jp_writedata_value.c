/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_writedata_value
*/

#include "../jp.h"

void jp_writedata_value(int fd, parsed_data_t *data, int tab_count)
{
    if (data->type == p_str) {
        jp_writestr(fd, "\"");
        jp_writestr(fd, data->value.p_str);
        jp_writestr(fd, "\"");
    }
    if (data->type == p_int)
        jp_writeint(fd, data->value.p_int);
    if (data->type == p_bool)
        jp_writebool(fd, data->value.p_bool);
    if (data->type == p_obj)
        jp_writedata(fd, data->value.p_obj, tab_count + 1);
    if (data->type == p_arr)
        jp_writearray(fd, data->value.p_arr, tab_count + 1);
}
