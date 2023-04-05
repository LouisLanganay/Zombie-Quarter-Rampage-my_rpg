/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_events
*/

#include "../gl.h"

void gl_delete_events(GLib_t *glib)
{
    events_t *tmp = glib->events;
    events_t *next = NULL;
    while (tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    glib->events = NULL;
}
