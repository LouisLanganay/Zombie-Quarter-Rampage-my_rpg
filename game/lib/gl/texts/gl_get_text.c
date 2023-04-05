/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_get_text
*/

#include "../gl.h"

sfText *gl_get_text(GLib_t *glib, int id)
{
    text_t *tmp = glib->texts;
    while (tmp != NULL) {
        if (tmp->id == id)
            return tmp->text;
        tmp = tmp->next;
    }
    return NULL;
}
