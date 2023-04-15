/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_item_name
*/

#include "rpg.h"
#include "jp.h"

char *get_item_name(int id)
{
    parsed_data_t *data = jp_parse("resources/jsons/items.json");
    int tmp;

    if (id == -1)
        return NULL;
    while (data) {
        tmp = jp_search(data->value.p_obj, "id")->value.p_int;
        if (tmp == id)
            return jp_search(data->value.p_obj, "name")->value.p_str;
        data = data->next;
    }
    return NULL;
}
