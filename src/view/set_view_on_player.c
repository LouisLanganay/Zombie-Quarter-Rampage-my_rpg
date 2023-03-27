/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_view_on_player
*/

#include "rpg.h"

void set_view_on_player(rpg_t *rpg)
{
    sfVector2f pos = rpg->player->pos;

    if (pos.x < MAP_MARGIN_X)
        pos.x = MAP_MARGIN_X;
    if (pos.y < MAP_MARGIN_Y)
        pos.y = MAP_MARGIN_Y;
    if (pos.x > rpg->glib->window->mode.width * 2 - MAP_MARGIN_X)
        pos.x = rpg->glib->window->mode.width * 2 - MAP_MARGIN_X;
    if (pos.y > rpg->glib->window->mode.height * 2 - MAP_MARGIN_Y)
        pos.y = rpg->glib->window->mode.height * 2 - MAP_MARGIN_Y;
    sfView_setCenter(rpg->player->view, pos);
    sfRenderWindow_setView(rpg->glib->window->window, rpg->player->view);
}
