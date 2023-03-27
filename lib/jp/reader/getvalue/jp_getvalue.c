/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_getvalue
*/

#include "../../jp.h"

static int jp_getvalue_suite(char **str, parsed_data_t *data)
{
    if (**str == '"') {
        data->type = p_str;
        data->value.p_str = jp_getvalue_string(str);
        return 1;
    }
    if ((**str >= '0' && **str <= '9') || **str == '-') {
        jp_getvalue_int(str, data);
        return 1;
    }
    if (**str == 't' || **str == 'f') {
        jp_getvalue_bool(str, data);
        return 1;
    }
    return 0;
}

void jp_getvalue(char **str, parsed_data_t *data)
{
    *str += 1;
    jp_skipspaces(str);
    if (**str == '{') {
        *str += 1;
        data->type = p_obj;
        data->value.p_obj = load_object(str);
        return;
    }
    if (**str == '[') {
        data->type = p_arr;
        data->value.p_arr = load_array(str);
        return;
    }
    if (jp_getvalue_suite(str, data) != 0)
        return;
    jp_skipspaces(str);
}
