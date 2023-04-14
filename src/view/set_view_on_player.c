/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** set_view_on_player
*/

#include "rpg.h"

static void set_view_on_player_zoom(rpg_t *rpg)
{
    time_t time = sfClock_getElapsedTime(rpg->player->view->clock).microseconds;
    float seconds = time / 1000000.0;

    if (rpg->player->view->time <= 0) return;
    if (seconds > 0.01) {
        sfView_zoom(rpg->player->view->view, rpg->player->view->zoom);
        sfClock_restart(rpg->player->view->clock);
        rpg->player->view->time -= 1;
        return;
    }

}

void set_view_on_player(rpg_t *rpg)
{
    sfVector2f pos = rpg->player->pos;
    map_t *map = get_map(rpg, rpg->actual_map);

    set_view_on_player_zoom(rpg);
    if (pos.x < MAP_MARGIN_X)
        pos.x = MAP_MARGIN_X;
    if (pos.y < MAP_MARGIN_Y)
        pos.y = MAP_MARGIN_Y;
    if (pos.x > map->map_width * 16 - MAP_MARGIN_X)
        pos.x = map->map_width * 16 - MAP_MARGIN_X;
    if (pos.y > map->map_height * 16 - MAP_MARGIN_Y)
        pos.y = map->map_height * 16 - MAP_MARGIN_Y;
    if (pos.x > rpg->glib->window->mode.width * 2 - MAP_MARGIN_X)
        pos.x = rpg->glib->window->mode.width * 2 - MAP_MARGIN_X;
    if (pos.y > rpg->glib->window->mode.height * 2 - MAP_MARGIN_Y)
        pos.y = rpg->glib->window->mode.height * 2 - MAP_MARGIN_Y;
    sfView_setCenter(rpg->player->view->view, pos);
    sfRenderWindow_setView(rpg->glib->window->window, rpg->player->view->view);
}
