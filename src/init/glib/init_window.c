/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_window
*/

#include "rpg.h"

void init_window(rpg_t *rpg)
{
    create_window_t *window = malloc(sizeof(create_window_t));
    window->width = 1920;
    window->height = 1080;
    window->title = WINDOW_NAME;
    window->framerate = 120;
    window->style = sfClose;
    rpg->glib->window = gl_create_window(window);
}
