/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** s_grocery
*/

#include "rpg.h"

void s_grocery(rpg_t *rpg, sfVector2f pos)
{
    (void)(pos);
    if (sfSound_getStatus(
            gl_get_sound(rpg->glib, GROCERY_SOUND_ID)->sound) != sfPlaying)
        start_sound(rpg, GROCERY_SOUND_ID);
}
