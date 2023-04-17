/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** note
*/

#include "rpg.h"

void note(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    rpg->player->lore_text = my_strdup(get_language(rpg,
        "note_paper", RSG));
    rpg->player->inventory->is_open = 0;
    rpg->player->lore_open = 1;
}
