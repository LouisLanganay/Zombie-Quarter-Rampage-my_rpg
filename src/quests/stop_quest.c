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

void stop_quest(rpg_t *rpg, char *id)
{
    int i = 0;

    while (rpg->quests_in_progress[i] != NULL) {
        if (my_strcmp(rpg->quests_in_progress[i], id) == 0) {
            remove_from_arr(rpg->quests_in_progress, i);
            break;
        }
        i++;
    }
}
