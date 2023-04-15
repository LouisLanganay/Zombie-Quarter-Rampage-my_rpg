/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** s_nature
*/

#include "rpg.h"

void s_nature_exit(rpg_t *rpg, sfVector2f pos)
{
    fade_sound(rpg, NATURE_SOUND_ID, 5);
}
