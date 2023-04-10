/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_quests
*/

#include "rpg.h"

static void add_quest(rpg_t *rpg, parsed_data_t *quest, char *id)
{
    quest_t *new_quest = malloc(sizeof(quest_t));

    new_quest->id = id;
    new_quest->name = jp_search(quest, "name")->value.p_str;
    new_quest->description = jp_search(quest, "description")->value.p_str;
    new_quest->type = jp_search(quest, "type")->value.p_str;
    if (jp_search(quest, "function")->type != p_null)
        new_quest->func = jp_search(quest, "function")->value.p_str;
    else
        new_quest->func = NULL;
    new_quest->next = rpg->quests;
    rpg->quests = new_quest;
}

void init_quests(rpg_t *rpg)
{
    parsed_data_t *data = jp_parse("resources/jsons/quests.json");
    rpg->quests = NULL;
    rpg->quests_in_progress = malloc(sizeof(char *) * 1);
    rpg->quests_in_progress[0] = NULL;
    rpg->quests_completed = malloc(sizeof(char *) * 1);
    rpg->quests_completed[0] = NULL;

    while (data->next != NULL) {
        add_quest(rpg, data->value.p_obj, data->name);
        data = data->next;
    }
}
