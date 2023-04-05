/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_scene
*/

#include "../gl.h"

static void gl_delete_scene_id(scenes_t *prev, scenes_t *tmp, GLib_t *glib)
{
    if (prev == NULL)
        glib->scenes = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp);
}

void gl_delete_scene(GLib_t *glib, int id)
{
    scenes_t *tmp = glib->scenes;
    scenes_t *prev = NULL;
    while (tmp) {
        if (tmp->id == id)
            return gl_delete_scene_id(prev, tmp, glib);
        prev = tmp;
        tmp = tmp->next;
    }
}
