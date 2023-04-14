/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_sounds
*/

#include "rpg.h"

static void remove_sound_from_linked_list_id(
    sounds_t *prev,
    sounds_t *tmp,
    rpg_t *rpg
)
{
    if (prev == NULL)
        rpg->sounds = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp);
}

static void remove_sound_from_linked_list(rpg_t *rpg, sounds_t *sound)
{
    sounds_t *tmp = rpg->sounds;
    sounds_t *prev = NULL;

    while (tmp) {
        if (tmp->id == sound->id)
            return remove_sound_from_linked_list_id(prev, tmp, rpg);
        prev = tmp;
        tmp = tmp->next;
    }
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
    sfSoundStatus status;
    float seconds;

    while (sound != NULL) {
        time = sfClock_getElapsedTime(sound->fade).microseconds;
        seconds = time / 1000000.0;
        status = sfSound_getStatus(gl_get_sound(rpg->glib, sound->id)->sound);
        if (status == sfStopped)
            remove_sound_from_linked_list(rpg, sound);
        if (sound->fade_time == 0)
            sfSound_setVolume(gl_get_sound(rpg->glib, sound->id)->sound, RSV);
        if (sound->fade_time != 0 && seconds >= sound->fade_time / 100)
            change_sound_vol(rpg, sound);
        sound = sound->next;
    }
}
