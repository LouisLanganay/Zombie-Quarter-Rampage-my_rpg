/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save_npc_interactions
*/

#include "rpg.h"

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

void save_npc_interactions(rpg_t *rpg)
{
    parsed_data_t *data = jp_parse(rpg->save->path);
    parsed_data_t *my_arr = malloc(sizeof(parsed_data_t));
    my_arr->type = p_str;
    my_arr->value.p_str = rpg->save->npc_interactions[0];
    my_arr->next = NULL;

    for (int i = 1; rpg->save->npc_interactions[i] != NULL; i++)
        add_node_to_my_arr(my_arr, rpg->save->npc_interactions[i]);

    jp_search(data, "game_timeline.npc_interactions")->value.p_arr = my_arr;
    jp_write(rpg->save->path, data);
}
