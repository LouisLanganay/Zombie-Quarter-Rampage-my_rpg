/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_scenes
*/

#include "../gl.h"

void gl_delete_scenes(GLib_t *glib)
{
    scenes_t *tmp = glib->scenes;
    scenes_t *next = NULL;
    while (tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    glib->scenes = NULL;
}
