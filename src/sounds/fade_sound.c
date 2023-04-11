/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** fade_sound
*/

#include "rpg.h"

void fade_sound(rpg_t *rpg, int id, float time)
{
    sounds_t *sound = rpg->sounds;

    while (sound != NULL) {
        if (sound->id == id) {
            sound->fade_time = time;
            sfClock_restart(sound->fade);
            return;
        }
        sound = sound->next;
    }
}
