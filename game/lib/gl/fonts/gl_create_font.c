/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_font
*/

#include "../gl.h"

static int gl_create_font_check_id(fonts_t *fonts, int id)
{
    fonts_t *tmp = fonts;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_font) Font id already exist\n", 39);
        tmp = tmp->next;
    }
    return (0);
}

int gl_create_font(GLib_t *glib, int id, char *path)
{
    if (gl_create_font_check_id(glib->fonts, id) != 0)
        return (84);
    fonts_t *tmp = malloc(sizeof(*tmp));
    tmp->id = id;
    tmp->font = sfFont_createFromFile(path);
    tmp->next = glib->fonts;
    glib->fonts = tmp;
}
