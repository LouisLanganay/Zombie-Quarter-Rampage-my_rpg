/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** change_window_mode
*/

#include "rpg.h"

void change_window_mode(rpg_t *rpg, wmode_t mode)
{
    create_window_t *window = malloc(sizeof(create_window_t));

    sfRenderWindow_destroy(rpg->glib->window->window);
    rpg->glib->window->window = sfRenderWindow_create(rpg->glib->window->mode,
        WINDOW_NAME, mode == FSCREEN ? sfFullscreen : sfClose, 0);
    rpg->settings->window_mode = mode;
}
