/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** quest_is_in_progress
*/

#include "rpg.h"

int quest_is_in_progress(rpg_t *rpg, char *quest_name)
{
    for (int i = 0; rpg->quests_in_progress[i]; i++) {
        if (my_strcmp(rpg->quests_in_progress[i], quest_name) == 0)
            return (1);
    }
    return (0);
}
