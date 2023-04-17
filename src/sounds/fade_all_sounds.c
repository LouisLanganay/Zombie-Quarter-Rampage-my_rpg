/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** fade_all_sounds
*/

#include "rpg.h"

void fade_all_sounds(rpg_t *rpg, float time)
{
    sounds_t *sound = rpg->sounds;

    while (sound != NULL) {
        sound->fade_time = time;
        sound = sound->next;
    }
}
