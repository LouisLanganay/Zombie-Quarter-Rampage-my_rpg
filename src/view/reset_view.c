/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** reset_view
*/

#include "rpg.h"

void reset_view(rpg_t *rpg)
{
    sfVector2f screen_size = (sfVector2f){
        rpg->glib->window->mode.width,
        rpg->glib->window->mode.height
    };
    sfView_destroy(RP->view->view);
    RP->view->view = init_view(screen_size, 0.3, 3);
    sfRenderWindow_setView(RGW->window, RP->view->view);
}
