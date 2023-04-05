/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** load_object
*/

#include "../../jp.h"

static void load_object_loop(char **str, parsed_data_t *data)
{
    for (; **str; *str += (**str == ',')) {
        data->next = NULL;
        jp_skipspaces(str);
        if (**str == '}') {
            data->type = p_null;
            break;
        }
        data->name = jp_getvalue_string(str);
        jp_skipspaces(str);
        for (; **str && **str != ':'; *str += 1);
        jp_getvalue(str, data);
        if (**str == '}')
            break;
        data->next = malloc(sizeof(parsed_data_t));
        data = data->next;
    }
}

parsed_data_t *load_object(char **str)
{
    parsed_data_t *data = malloc(sizeof(parsed_data_t));
    parsed_data_t *tmp = data;

    if (**str == '{')
        *str += 1;

    load_object_loop(str, data);

    *str += (**str == '}');
    return (tmp);
}
