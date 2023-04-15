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
    if (sfSound_getStatus(
            gl_get_sound(rpg->glib, RADIATION_SOUND_ID)->sound) != sfPlaying)
        start_sound(rpg, RADIATION_SOUND_ID);
}
