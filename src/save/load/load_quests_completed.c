/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_quests_completed
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

int load_quests_completed(rpg_t *rpg, parsed_data_t *data)
{
    data = data->value.p_obj;
    parsed_data_t *arr = jp_search(data, "quests_completed")->value.p_arr;
    if (arr == NULL) return (0);
    int size = count_arr(arr);
    rpg->quests_completed = malloc(sizeof(char *) * (size + 1));

    if (arr->value.p_str == NULL) return (0);
    for (int i = 0; i < size; i++) {
        rpg->quests_completed[i] = my_strdup(arr->value.p_str);
        arr = arr->next;
    }
    rpg->quests_completed[size] = NULL;
    return (0);
}
