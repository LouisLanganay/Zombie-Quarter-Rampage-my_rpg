/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** event_seetings.c
*/

#include "rpg.h"

void e_close(window_t *window, void *main)
{
    (void)window;
    rpg_t *rpg = (rpg_t *)main;
    sfRenderWindow_close(rpg->glib->window->window);
}
