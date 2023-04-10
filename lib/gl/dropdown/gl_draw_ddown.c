/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_ddown
*/

#include "../gl.h"

static void gl_draw_ddown_id(dropdown_t *ddown, GLib_t *glib)
{
    sfRectangleShape_setPosition(ddown->background, (sfVector2f){
        ddown->pos.x - 10, ddown->pos.y
    });
    sfRenderWindow_drawRectangleShape(glib->window->window,
        ddown->background, NULL);
    if (ddown->text_id)
        gl_draw_text(glib, ddown->text_id);
}

void gl_draw_ddown(int id, window_t *window, GLib_t *glib)
{
    dropdown_t *tmp = glib->ddowns;
    while (tmp != NULL) {
        if (tmp->id == id) {
            gl_draw_ddown_id(tmp, glib);
            return;
        }
        tmp = tmp->next;
    }
    write(2, "(gl_draw_ddown) Ddown id not found\n", 36);
}
