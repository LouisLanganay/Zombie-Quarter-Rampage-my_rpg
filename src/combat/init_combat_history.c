/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_combat_history
*/

#include "rpg.h"

void init_combat_history(rpg_t *rpg)
{
    rpg->combat_history = malloc(sizeof(combat_history_t));
    rpg->combat_history->i_lauch_combat1_status = 0;
    rpg->combat_history->i_lauch_combat2_status = 0;
    rpg->combat_history->i_lauch_combat3_status = 0;
}
