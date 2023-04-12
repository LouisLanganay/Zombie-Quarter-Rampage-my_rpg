/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_event_create
*/

#include "../gl.h"

static int gl_create_event_check_id(events_t *events, int id)
{
    events_t *tmp = events;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_event) Event id already exist\n", 41);
        tmp = tmp->next;
    }
    return (0);
}

int gl_create_event(
    GLib_t *glib,
    int id,
    sfEventType type,
    void (*event)(window_t *window, void *main)
)
{
    if (gl_create_event_check_id(glib->events, id) != 0)
        return 84;

    events_t *tmp = malloc(sizeof(*tmp));
    if (tmp == NULL)
        return write(2, "(gl_create_event) Malloc failed\n", 32);

    tmp->id = id;
    tmp->type = type;
    tmp->event = event;

    tmp->next = glib->events;
    glib->events = tmp;
}
