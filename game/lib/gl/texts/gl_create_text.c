/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_text
*/

#include "../gl.h"

static int gl_create_text_check_id(text_t *texts, int id)
{
    text_t *tmp = texts;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_text) Text id already exist\n", 39);
        tmp = tmp->next;
    }
    return (0);
}

int gl_create_text(GLib_t *glib, text_t *text)
{
    if (gl_create_text_check_id(glib->texts, text->id) != 0)
        return (84);
    text_t *tmp = malloc(sizeof(*tmp));
    tmp->id = text->id;
    tmp->pos = text->pos;
    tmp->font = text->font;
    tmp->scale = text->scale;
    tmp->color = text->color;
    tmp->string = text->string;
    tmp->size = text->size;
    tmp->text = sfText_create();
    sfText_setColor(tmp->text, tmp->color);
    sfText_setString(tmp->text, tmp->string);
    sfText_setPosition(tmp->text, tmp->pos);
    sfText_setScale(tmp->text, tmp->scale);
    sfText_setFont(tmp->text, tmp->font);
    sfText_setCharacterSize(tmp->text, tmp->size);
    tmp->next = glib->texts;
    glib->texts = tmp;
}
