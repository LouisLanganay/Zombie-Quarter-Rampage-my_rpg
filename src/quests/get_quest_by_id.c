/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_quest_by_id
*/

#include "rpg.h"

quest_t *get_quest_by_id(rpg_t *rpg, char *id)
{
    quest_t *quest = rpg->quests;

    while (quest != NULL) {
        if (my_strcmp(quest->id, id) == 0)
            return quest;
        quest = quest->next;
    }
    return NULL;
}
