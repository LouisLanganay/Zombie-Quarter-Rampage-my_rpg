/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_init_window
*/

#include "../gl.h"

static int handle_error(int width, int height, char *title, int framerate)
{
    if (width <= 0 || height <= 0)
        return write(2, "(gl_init_window) width or height is invalid\n", 44);
    if (framerate <= 0)
        return write(2, "(gl_init_window) framerate is invalid\n", 38);
    if (width > 1920 || height > 1080)
        return write(2, "(gl_init_window) width or height is too big\n", 44);
    return 0;
}

window_t *gl_create_window(create_window_t *my_window)
{
    if (handle_error(my_window->width, my_window->height, my_window->title,
        my_window->framerate) != 0)
        return NULL;

    window_t *window = malloc(sizeof(window_t));

    window->mode = (sfVideoMode){my_window->width, my_window->height, 32};
    window->window = sfRenderWindow_create(window->mode,
        my_window->title, my_window->style, 0);
    window->clock = sfClock_create();
    window->event;

    if (!window->window)
        return NULL;

    sfRenderWindow_setFramerateLimit(window->window, my_window->framerate);
    free(my_window);
    return (window);
}
