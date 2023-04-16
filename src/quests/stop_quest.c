/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** stop_quest
*/

#include "rpg.h"

static void remove_from_arr(char **arr, int i)
{
    arr[i] = NULL;
    for (int j = i; arr[j] != NULL; j++) {
        arr[j] = arr[j + 1];
    }
}

static void exe_quest_function(rpg_t *rpg, quest_t *quest)
{
    quests_func_t *arr = get_quests_func_arr();

    for (long unsigned int i = 0; arr[i].name; i++) {
        if (my_strcmp(arr[i].name, quest->func) == 0) {
            arr[i].func(rpg);
            break;
        }
    }
}

void stop_quest(rpg_t *rpg, char *id)
{
    int i = 0;

    while (rpg->quests_in_progress[i] != NULL) {
        if (my_strcmp(rpg->quests_in_progress[i], id) == 0) {
            exe_quest_function(rpg, get_quest_by_id(rpg, id));
            remove_from_arr(rpg->quests_in_progress, i);
            rpg->quests_completed = add_item_to_arr(rpg->quests_completed, id);
            break;
        }
        i++;
    }
}
