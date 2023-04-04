/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_getvalue_bool
*/

#include "../../jp.h"

void jp_getvalue_bool(char **str, parsed_data_t *data)
{
    if (**str == 't') {
        data->type = p_bool;
        data->value.p_bool = b_true;
        *str += 4;
        return;
    }
    if (**str == 'f') {
        data->type = p_bool;
        data->value.p_bool = b_false;
        *str += 5;
        return;
    }
}
