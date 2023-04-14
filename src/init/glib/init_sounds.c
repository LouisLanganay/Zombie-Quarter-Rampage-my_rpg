/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_sounds
*/

#include "rpg.h"

static void init_sound_inventory(GLib_t *glib, sound_t *my_sound)
{
    my_sound->id = INV_SOUND_ID;
    my_sound->sound = sfSound_create();
    my_sound->buffer = sfSoundBuffer_createFromFile(INV_SOUND_PATH);
    gl_create_sound(glib, my_sound);

    my_sound->id = DROP_SOUND_ID;
    my_sound->sound = sfSound_create();
    my_sound->buffer = sfSoundBuffer_createFromFile(DROP_SOUND_PATH);
    gl_create_sound(glib, my_sound);
}

void init_sounds(GLib_t *glib)
{
    glib->sounds = NULL;
    sound_t *my_sound = malloc(sizeof(sound_t));
    my_sound->id = XP_SOUND_ID;
    my_sound->sound = sfSound_create();
    my_sound->buffer = sfSoundBuffer_createFromFile(XP_SOUND_PATH);
    gl_create_sound(glib, my_sound);

    my_sound->id = MAIN_THEME_ID;
    my_sound->sound = sfSound_create();
    my_sound->buffer = sfSoundBuffer_createFromFile(MAIN_THEME_PATH);
    gl_create_sound(glib, my_sound);

    my_sound->id = BASEMENT_SOUND_ID;
    my_sound->sound = sfSound_create();
    my_sound->buffer = sfSoundBuffer_createFromFile(BASEMENT_SOUND_PATH);
    gl_create_sound(glib, my_sound);

    init_sound_inventory(glib, my_sound);

}
