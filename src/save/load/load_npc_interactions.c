/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_npc_interactions
*/

#include "rpg.h"

static int count_arr(parsed_data_t *arr)
{
    int i = 0;

    while (arr != NULL) {
        i++;
        arr = arr->next;
    }
    return (i);
}

int load_npc_interactions(save_t *save, parsed_data_t *data)
{
    data = data->value.p_obj;
    parsed_data_t *arr = jp_search(data, "npc_interactions")->value.p_arr;
    int size = count_arr(arr);
    save->npc_interactions = malloc(sizeof(char *) * (size + 1));

    if (arr->value.p_str == NULL) return (0);
    for (int i = 0; i < size; i++) {
        save->npc_interactions[i] = my_strdup(arr->value.p_str);
        arr = arr->next;
    }
    save->npc_interactions[size] = NULL;
    return (0);
}
