/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_end
*/

#include "rpg.h"

void i_end(rpg_t *rpg, sfVector2f pos)
{
    (void)(pos);
    if (rpg->game_state == GAME_WIN) return;
    rpg->game_state = GAME_WIN;
    sfClock_restart(rpg->player->game_win->clock);
}
