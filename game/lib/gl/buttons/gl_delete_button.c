/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_button
*/

#include "../gl.h"

static void gl_delete_button_id(buttons_t *prev, buttons_t *tmp, GLib_t *glib)
{
    if (prev == NULL)
        glib->buttons = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp);
}

void gl_delete_button(GLib_t *glib, int id)
{
    buttons_t *tmp = glib->buttons;
    buttons_t *prev = NULL;
    while (tmp) {
        if (tmp->id == id)
            return gl_delete_button_id(prev, tmp, glib);
        prev = tmp;
        tmp = tmp->next;
    }
}
