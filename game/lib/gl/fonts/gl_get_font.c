/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_get_font
*/

#include "../gl.h"

sfFont *gl_get_font(GLib_t *glib, int id)
{
    fonts_t *tmp = glib->fonts;
    while (tmp != NULL) {
        if (tmp->id == id)
            return tmp->font;
        tmp = tmp->next;
    }
    return NULL;
}
