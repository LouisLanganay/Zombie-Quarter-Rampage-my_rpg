/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** hunger_lost
*/

#include "rpg.h"

void hunger_lost(rpg_t *rpg)
{
    time_t time = sfClock_getElapsedTime(RP->hunger_lost).microseconds;
    float seconds = time / 1000000.0;

    if (seconds > 5) {
        if (RP->hunger > 0)
            RP->hunger -= 1;
        else
            RP->hp -= 2;
        sfClock_restart(RP->hunger_lost);
    }
}
