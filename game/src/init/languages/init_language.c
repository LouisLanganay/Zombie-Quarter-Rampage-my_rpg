/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_language
*/

#include "rpg.h"

static int language_count(parsed_data_t *data)
{
    parsed_data_t *tmp = data;
    int count = 0;

    while (tmp->next) {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

void init_language(rpg_t *rpg)
{
    parsed_data_t *data = jp_parse("resources/jsons/language.json");
    rpg->languages = malloc(sizeof(languages_t *) * (language_count(data) + 1));
    rpg->languages[language_count(data)] = NULL;
    parsed_data_t *tmp = data;

    for (int i = 0; i < language_count(data); i++) {
        rpg->languages[i] = malloc(sizeof(languages_t));
        rpg->languages[i]->name = tmp->name;
        rpg->languages[i]->en = jp_search(tmp->value.p_obj, "en")->value.p_str;
        rpg->languages[i]->fr = jp_search(tmp->value.p_obj, "fr")->value.p_str;
        tmp = tmp->next;
    }
}
