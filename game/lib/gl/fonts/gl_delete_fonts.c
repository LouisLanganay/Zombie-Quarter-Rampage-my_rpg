/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_fonts
*/

#include "../gl.h"

void gl_delete_fonts(GLib_t *glib)
{
    fonts_t *tmp = glib->fonts;
    fonts_t *prev = NULL;
    while (tmp != NULL) {
        if (prev == NULL)
            glib->fonts = tmp->next;
        else
            prev->next = tmp->next;
        sfFont_destroy(tmp->font);
        free(tmp);
        prev = tmp;
        tmp = tmp->next;
    }
}
