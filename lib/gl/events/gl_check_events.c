/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_check_events
*/

#include "../gl.h"

static int handle_errors(window_t *window, events_t *events)
{
    if (!window || !events)
        write(2, "(gl_check_events) window or events is NULL\n", 43);
    return (0);
}

static events_t *gl_check_events_each(
    window_t *window,
    events_t *tmp,
    void *main
)
{
    if (window->event.type == tmp->type)
        tmp->event(window, main);
    tmp = tmp->next;
    return tmp;
}

void gl_check_events(window_t *window, events_t *events, void *main)
{
    if (handle_errors(window, events) != 0)
        exit(84);
    events_t *tmp = events;
    while (sfRenderWindow_pollEvent(window->window, &window->event)) {
        tmp = events;
        while (tmp) {
            tmp = gl_check_events_each(window, tmp, main);
        }
    }
}
