/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_texts
*/

#include "../gl.h"

void gl_draw_texts(GLib_t *glib)
{
    text_t *tmp = glib->texts;
    while (tmp != NULL) {
        sfRenderWindow_drawText(glib->window->window, tmp->text, NULL);
        tmp = tmp->next;
    }
}
