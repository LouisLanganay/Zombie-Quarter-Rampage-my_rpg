/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_sound
*/

#include "../gl.h"

static int gl_create_sound_check_id(sound_t *sounds, int id)
{
    sound_t *tmp = sounds;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_sound) Sound id already exist\n", 41);
        tmp = tmp->next;
    }
    return (0);
}

int gl_create_sound(GLib_t *glib, sound_t *sound)
{
    if (gl_create_sound_check_id(glib->sounds, sprite->id) != 0)
        return (84);
    sound_t *tmp = malloc(sizeof(*tmp));
    tmp->id = sound->id;
    tmp->sound = sound->sound;
    tmp->buffer = sound->buffer;
    sfSound_setBuffer(tmp->sound, tmp->buffer);

    tmp->next = glib->sounds;
    glib->sounds = tmp;
}
