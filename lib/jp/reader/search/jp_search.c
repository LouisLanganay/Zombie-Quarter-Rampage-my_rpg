/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_search
*/

#include "../../jp.h"

#include <string.h>

static parsed_data_t *jp_get_arr(parsed_data_t *data, char *name)
{
    int i = 0;
    parsed_data_t *tmp = data->value.p_arr;

    while (name[i] != '[')
        i++;
    i++;
    for (int j = 0; j < name[i] - '0'; j++) {
        tmp = tmp->next;
    }
    if (tmp->type == p_obj)
        return (tmp->value.p_obj);
    if (tmp->type == p_str)
        return (tmp);
    if (tmp->type == p_int)
        return (tmp);
    if (tmp->type == p_bool)
        return (tmp);
}

static parsed_data_t *find_obj(parsed_data_t *tmp, char *tmp_name)
{
    while (tmp->next != NULL) {
        if (tmp->name && my_strcmp(tmp->name, tmp_name) == 0)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

parsed_data_t *jp_search(parsed_data_t *data, char *name)
{
    parsed_data_t *tmp = data;
    char *tmp_name = get_name(name);
    int is_arr = is_array(name);
    if (is_arr == 1) {
        char *tmp_name_arr = tmp_name;
        tmp_name = get_name_without_arr(tmp_name_arr);
    }
    tmp = find_obj(tmp, tmp_name);
    if (name[name_len(name)] == '\0') {
        if (is_arr == 1)
            return (jp_get_arr(tmp, name));
        else
            return (tmp);
    } else {
        if (is_arr == 1)
            return (jp_search(jp_get_arr(tmp, name), name + name_len(name) +1));
        else
            return (jp_search(tmp->value.p_obj, name + name_len(name) + 1));
    }
    return (NULL);
}
