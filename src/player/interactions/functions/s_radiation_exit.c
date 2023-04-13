/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** s_radiation
*/

#include "rpg.h"

void s_radiation_exit(rpg_t *rpg, sfVector2f pos)
{
    fade_sound(rpg, RADIATION_SOUND_ID, 10);
}
