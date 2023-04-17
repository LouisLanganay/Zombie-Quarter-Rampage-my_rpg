/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_lauch_combat
*/

#include "rpg.h"

void i_lauch_combat(rpg_t *rpg, sfVector2f pos)
{
    (void)pos;
    if (rpg->combat_history->i_lauch_combat1_status == 0) {
        rpg->combat_history->i_lauch_combat1_status = 1;
        combat(rpg);
    }
}
