/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save_quests_completed
*/

#include "rpg.h"

static char **get_new_arr(rpg_t *rpg)
{
    int size = my_arrlen(rpg->quests_completed);
    char **new_arr = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i < size; i++)
        new_arr[i] = my_strdup(rpg->quests_completed[i]);
    new_arr[size] = NULL;

    return new_arr;
}

static void add_node_to_my_arr(parsed_data_t *my_arr, char *str)
{
    if (my_arr == NULL) return;
    parsed_data_t *tmp = my_arr;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(parsed_data_t));
    if (tmp->next == NULL) return;
    tmp->next->type = p_str;
    tmp->next->value.p_str = str;
    tmp->next->next = NULL;
}

void save_quests_completed(rpg_t *rpg)
{
    char **new_arr = get_new_arr(rpg);
    parsed_data_t *data = jp_parse(rpg->save->path);
    parsed_data_t *my_arr = malloc(sizeof(parsed_data_t));
    my_arr->type = p_str;
    my_arr->value.p_str = new_arr[0];
    my_arr->next = NULL;

    for (int i = 1; new_arr[i] != NULL; i++)
        add_node_to_my_arr(my_arr, new_arr[i]);

    jp_search(data, "game_timeline.quests_completed")->value.p_arr = my_arr;
    jp_write(rpg->save->path, data);
    free(new_arr);
}
