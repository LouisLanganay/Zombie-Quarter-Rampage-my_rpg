/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** s_house
*/

#include "rpg.h"

void s_house(rpg_t *rpg, sfVector2f pos)
{
    (void)(pos);
    fade_sound(rpg, BASEMENT_SOUND_ID, 5);
}
