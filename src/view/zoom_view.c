/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** zoom_view
*/

#include "rpg.h"

void zoom_view(rpg_t *rpg, float value, float time)
{
    rpg->player->view->zoom = value;
    rpg->player->view->time = time;
    sfClock_restart(rpg->player->view->clock);
}
