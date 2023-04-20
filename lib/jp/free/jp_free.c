/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_free
*/

#include "../jp.h"

void jp_free(parsed_data_t *data)
{
    if (data->type == p_obj)
        jp_free(data->value.p_obj);
    if (data->type == p_str)
        free(data->value.p_str);
    if (data->type == p_arr) {
        if (data->value.p_arr->type == p_obj)
            jp_free(data->value.p_arr->value.p_obj);
    }
    if (data->next->type != p_null)
        jp_free(data->next);
    free(data);
}
