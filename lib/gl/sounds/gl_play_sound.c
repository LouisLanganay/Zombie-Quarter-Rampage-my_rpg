/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_play_sound
*/

#include "../gl.h"

void gl_play_sound(GLib_t *glib, int id)
{
    sound_t *tmp = glib->sounds;

    while (tmp != NULL) {
        if (tmp->id == id) {
            sfSound_play(tmp->sound);
            return;
        }
        tmp = tmp->next;
    }
}
