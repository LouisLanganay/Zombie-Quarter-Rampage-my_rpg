/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_text
*/

#include "../gl.h"

static void gl_delete_font_id(fonts_t *prev, fonts_t *tmp, GLib_t *glib)
{
    if (prev == NULL)
        glib->fonts = tmp->next;
    else
        prev->next = tmp->next;
    sfFont_destroy(tmp->font);
    free(tmp);
}

void gl_delete_font(GLib_t *glib, int id)
{
    fonts_t *tmp = glib->fonts;
    fonts_t *prev = NULL;
    while (tmp != NULL) {
        if (tmp->id == id)
            return gl_delete_font_id(prev, tmp, glib);
        prev = tmp;
        tmp = tmp->next;
    }
}
