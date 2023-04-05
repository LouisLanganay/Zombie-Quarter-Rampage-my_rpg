/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** load_layer_data_arr
*/

#include "rpg.h"

int *load_layer_data_arr(parsed_data_t *data)
{
    int height = jp_search(data, "height")->value.p_int;
    int width = jp_search(data, "width")->value.p_int;
    int *arr = malloc(sizeof(int) * (height * width));
    parsed_data_t *data_arr = jp_search(data, "data")->value.p_arr;

    for (int i = 0; i < height * width; i++) {
        arr[i] = data_arr->value.p_int;
        data_arr = data_arr->next;
    }

    return arr;
}
