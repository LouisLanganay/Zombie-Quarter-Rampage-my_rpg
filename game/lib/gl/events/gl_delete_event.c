/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_event
*/

#include "../gl.h"

static void gl_delete_event_id(events_t *prev, events_t *tmp, GLib_t *glib)
{
    if (prev == NULL)
        glib->events = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp);
}

void gl_delete_event(GLib_t *glib, int id)
{
    events_t *tmp = glib->events;
    events_t *prev = NULL;
    while (tmp) {
        if (tmp->id == id)
            return gl_delete_event_id(prev, tmp, glib);
        prev = tmp;
        tmp = tmp->next;
    }
}
