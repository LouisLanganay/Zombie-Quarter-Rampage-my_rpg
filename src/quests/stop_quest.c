/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** stop_quest
*/

#include "rpg.h"

static void remove_from_arr(char **arr, int i, rpg_t *rpg)
{
    rpg->quests_in_progress[i] = NULL;
    for (int j = i; rpg->quests_in_progress[j] != NULL; j++) {
        rpg->quests_in_progress[j] = rpg->quests_in_progress[j + 1];
    }
}

void stop_quest(rpg_t *rpg, char *id)
{
    int i = 0;

    while (rpg->quests_in_progress[i] != NULL) {
        if (my_strcmp(rpg->quests_in_progress[i], id) == 0) {
            remove_from_arr(rpg->quests_in_progress, i, rpg);
            break;
        }
        i++;
    }
}
