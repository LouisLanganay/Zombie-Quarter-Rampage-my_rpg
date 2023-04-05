/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_texts
*/

#include "../gl.h"

void gl_delete_texts(GLib_t *glib)
{
    text_t *tmp = glib->texts;
    text_t *prev = NULL;
    while (tmp != NULL) {
        if (prev == NULL)
            glib->texts = tmp->next;
        else
            prev->next = tmp->next;
        sfText_destroy(tmp->text);
        sfFont_destroy(tmp->font);
        free(tmp);
        prev = tmp;
        tmp = tmp->next;
    }
}
