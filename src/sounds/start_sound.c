/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_sound
*/

#include "rpg.h"

static int check_if_sound_is_already_playing(rpg_t *rpg, int id)
{
    sounds_t *sound = rpg->sounds;

    while (sound != NULL) {
        if (sound->id == id)
            return 1;
        sound = sound->next;
    }
    return 0;
}

static void add_sound_to_linked_list(rpg_t *rpg, int id)
{
    sounds_t *tmp = malloc(sizeof(*tmp));
    tmp->id = id;
    tmp->start = sfClock_create();
    tmp->fade = sfClock_create();
    tmp->fade_time = 0;

    tmp->next = rpg->sounds;
    rpg->sounds = tmp;
}

void start_sound(rpg_t *rpg, int id)
{
    if (check_if_sound_is_already_playing(rpg, id) == 1) return;
    add_sound_to_linked_list(rpg, id);
    sfSound_setVolume(gl_get_sound(rpg->glib, id)->sound, RSV);
    gl_play_sound(rpg->glib, id);
}
