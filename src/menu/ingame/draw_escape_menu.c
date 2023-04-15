/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_escape_menu
*/

#include "rpg.h"


void draw_escape_menu(rpg_t *rpg)
{
    int width = rpg->glib->window->mode.width;
    int height = rpg->glib->window->mode.height;
    sfVector2f view_pos = sfView_getCenter(RP->view->view);

    if (rpg->game_state != PAUSE) return;
    sfRectangleShape_setPosition(rpg->background->bg_escape,
    (sfVector2f){view_pos.x - width / 2, view_pos.y - height / 2});
    sfRenderWindow_drawRectangleShape(RGWW, rpg->background->bg_escape, NULL);
}
