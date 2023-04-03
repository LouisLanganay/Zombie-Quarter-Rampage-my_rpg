/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_save
*/

#include "rpg.h"

void init_save(rpg_t *rpg)
{
    rpg->save = malloc(sizeof(save_t));
    rpg->save->format = NULL;
    rpg->save->name = NULL;
    rpg->save->path = NULL;
    rpg->save->npc_interactions = NULL;
}
