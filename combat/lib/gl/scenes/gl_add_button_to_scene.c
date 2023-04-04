/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_add_button_to_scene
*/

#include "../gl.h"

static int gl_scene_found(int scene_id, int button_id, scenes_t *tmp)
{
    int x = SCENE_ARRAY_SIZE;
    for (int i = 0; i < x; i++) {
        if (tmp->buttons[i] == button_id) {
            write(2, "(gl_add_button_to_scene) Button already in scene\n", 49);
            return 84;
        }
    }
    for (int i = 0; i < x; i++) {
        if (tmp->buttons[i] == 0) {
            tmp->buttons[i] = button_id;
            return 0;
        }
    }
}

int gl_add_button_to_scene(GLib_t *glib, int scene_id, int button_id)
{
    scenes_t *tmp = glib->scenes;
    while (tmp) {
        if (tmp->id == scene_id) {
            return gl_scene_found(scene_id, button_id, tmp);
        }
        tmp = tmp->next;
    }
    write(2, "(gl_add_button_to_scene) Scene not found\n", 41);
    return 84;
}
