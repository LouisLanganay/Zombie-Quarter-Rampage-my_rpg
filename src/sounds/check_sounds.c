/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_sounds
*/

#include "rpg.h"

static void remove_sound_from_linked_list(rpg_t *rpg, sounds_t *sound)
{
    sounds_t *tmp = rpg->sounds;

    if (tmp == sound) {
        rpg->sounds = tmp->next;
        free(tmp);
        return;
    }
    while (tmp->next != sound)
        tmp = tmp->next;
    tmp->next = sound->next;
    free(sound);
}

static void change_sound_vol(rpg_t *rpg, sounds_t *sound)
{
    float vol = sfSound_getVolume(gl_get_sound(rpg->glib, sound->id)->sound);
    sfSound *tmp = gl_get_sound(rpg->glib, sound->id)->sound;

    if (vol > 1) {
        sfSound_setVolume(tmp, vol - 1);
        sfClock_restart(sound->fade);
    } else {
        sfSound_stop(tmp);
        sfSound_setVolume(tmp, 100);
        remove_sound_from_linked_list(rpg, sound);
    }
}

void check_sounds(rpg_t *rpg)
{
    sounds_t *sound = rpg->sounds;
    time_t time;
    float seconds;

    while (sound != NULL) {
        time = sfClock_getElapsedTime(sound->fade).microseconds;
        seconds = time / 1000000.0;
        if (sound->fade_time == 0) {
            sound = sound->next;
            continue;
        }
        if (seconds >= sound->fade_time / 100)
            change_sound_vol(rpg, sound);
        sound = sound->next;
    }
}
