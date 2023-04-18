/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** s_nature
*/

#include "rpg.h"


void s_nature(rpg_t *rpg, sfVector2f pos)
{
    (void)pos;
    if (sfSound_getStatus(
            gl_get_sound(rpg->glib, NATURE_SOUND_ID)->sound) != sfPlaying)
        start_sound(rpg, NATURE_SOUND_ID);
}
