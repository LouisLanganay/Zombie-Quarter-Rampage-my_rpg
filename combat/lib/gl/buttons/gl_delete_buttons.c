/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_buttons
*/

#include "../gl.h"

void gl_delete_buttons(GLib_t *glib)
{
    buttons_t *tmp = glib->buttons;
    buttons_t *next = NULL;
    while (tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    glib->buttons = NULL;
}
