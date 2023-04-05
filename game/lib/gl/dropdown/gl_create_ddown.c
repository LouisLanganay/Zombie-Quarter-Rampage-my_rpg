/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_ddown
*/

#include "../gl.h"

static int gl_create_ddown_check_id(dropdown_t *ddowns, int id)
{
    dropdown_t *tmp = ddowns;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_ddown) Ddown id already exist\n", 42);
        tmp = tmp->next;
    }
    return (0);
}

static int handle_error(dropdown_t *ddown)
{
    if (ddown->id < 1)
        return write(2,
            "(gl_create_dddown) Ddown id can't be negative or 0\n", 51);
    if (ddown->pos.x < 0 || ddown->pos.y < 0)
        return write(2,
            "(gl_create_dddown) Ddown position can't be negative\n", 53);
    return (0);
}

int gl_create_ddown(GLib_t *glib, dropdown_t *ddown)
{
    if (gl_create_ddown_check_id(glib->ddowns, ddown->id) != 0)
        return (84);
    if (handle_error(ddown) != 0)
        return (84);
    dropdown_t *tmp = malloc(sizeof(*tmp));
    tmp->id = ddown->id;
    tmp->hovered = sfFalse;
    tmp->disabled = sfFalse;
    tmp->pos = ddown->pos;
    tmp->background = ddown->background;
    tmp->bg_colors = ddown->bg_colors;
    tmp->text_id = ddown->text_id;
    tmp->call_action = ddown->call_action;
    tmp->childs = NULL;
    tmp->next = glib->ddowns;
    glib->ddowns = tmp;
    free(ddown);
    return (0);
}
