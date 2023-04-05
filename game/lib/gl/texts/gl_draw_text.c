/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_text
*/

#include "../gl.h"

void gl_draw_text(GLib_t *glib, int id)
{
    text_t *tmp = glib->texts;
    while (tmp != NULL) {
        if (tmp->id == id) {
            sfRenderWindow_drawText(glib->window->window, tmp->text, NULL);
            return;
        }
        tmp = tmp->next;
    }
    write(2, "(gl_draw_text) Text id not found\n", 33);
}
