/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_scene
*/

#include "../gl.h"

static void gl_draw_scene_buttons(
    window_t *window,
    scenes_t *tmp,
    buttons_t *buttons
)
{
    int x = SCENE_ARRAY_SIZE;
    for (int i = 0; i < x; i++)
        if (tmp->buttons[i] != 0)
            gl_draw_button(tmp->buttons[i], buttons, window);
}

//// DRAW SPRITES
//// DRAW TEXTS

void gl_draw_scene(GLib_t *glib, int id)
{
    scenes_t *tmp = glib->scenes;
    while (tmp != NULL) {
        if (tmp->id == id) {
            gl_draw_scene_buttons(glib->window, tmp, glib->buttons);
            return;
        }
        tmp = tmp->next;
    }
}
