/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_sounds
*/

#include "rpg.h"

void init_sounds(GLib_t *glib)
{
    glib->sounds = NULL;
    sound_t *my_sound = malloc(sizeof(sound_t));
    my_sound->id = XP_SOUND_ID;
    my_sound->sound = sfSound_create();
    my_sound->buffer = sfSoundBuffer_createFromFile(XP_SOUND_PATH);
    gl_create_sound(glib, my_sound);
}
