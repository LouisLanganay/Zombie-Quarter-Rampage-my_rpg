/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** animation_zombies
*/

#include "rpg.h"

void animation_zombie_id(zombies_t *l, int id)
{
    if (id == 1)
        animation_zombie1(l);
    if (id == 2)
        animation_witch1(l);
}

void animation_zombie(zombies_t *l)
{
    zombies_t *tmp = l;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        if (sfs(sfClock_getElapsedTime(tmp->clock_animation)) > 0.15) {
            tmp->animation++;
            animation_zombie_id(tmp, tmp->type);
            sfClock_restart(tmp->clock_animation);
        }

        tmp = tmp->next;
    }
}
