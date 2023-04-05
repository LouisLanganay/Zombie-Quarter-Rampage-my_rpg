/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_language
*/

#include "rpg.h"

static char *get_language_type(language_type_t language, int i, rpg_t *rpg)
{
    if (language == EN) {
        if (rpg->languages[i]->en)
            return (rpg->languages[i]->en);
        else
            return (NULL);
    }
    if (language == FR) {
        if (rpg->languages[i]->fr)
            return (rpg->languages[i]->fr);
        else
            return (NULL);
    }
    return (NULL);
}

char *get_language(rpg_t *rpg, char *name, language_type_t language)
{
    for (int i = 0; rpg->languages[i]; i++)
        if (my_strcmp(rpg->languages[i]->name, name) == 0)
            return (get_language_type(language, i, rpg));
    return (NULL);
}
