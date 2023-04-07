/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** e_close
*/

#include "rpg.h"

void e_close(window_t *window, void *main)
{
    (void)window;
    rpg_t *rpg = (rpg_t *)main;
    sfRenderWindow_close(rpg->glib->window->window);
    sfRenderWindow_destroy(rpg->glib->window->window);
}
    