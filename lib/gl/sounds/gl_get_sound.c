/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_get_sound
*/

#include "../gl.h"

sound_t *gl_get_sound(GLib_t *glib, int id)
{
    sound_t *tmp = glib->sounds;

    while (tmp != NULL) {
        if (tmp->id == id)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
