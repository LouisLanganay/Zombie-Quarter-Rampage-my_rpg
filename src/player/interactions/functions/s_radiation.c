/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** s_radiation
*/

#include "rpg.h"

void s_radiation(rpg_t *rpg, sfVector2f pos)
{
    (void)(pos);
    time_t time = sfClock_getElapsedTime(rpg->player->hp_clock).microseconds;
    float seconds = time / 1000000.0;
    if (check_if_items_is_here(rpg, 31) == 1)
        return;
    if (sfSound_getStatus(
            gl_get_sound(rpg->glib, RADIATION_SOUND_ID)->sound) != sfPlaying)
        start_sound(rpg, RADIATION_SOUND_ID);
    if (seconds > 0.2) {
        if (rpg->player->hp > 0)
            rpg->player->hp -= 1;
        sfClock_restart(rpg->player->hp_clock);
    }
}
