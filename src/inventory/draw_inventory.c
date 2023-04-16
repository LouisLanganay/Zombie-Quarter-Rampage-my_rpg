/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_inventory
*/

#include "rpg.h"

void draw_inventory(rpg_t *rpg)
{
    int width = rpg->glib->window->mode.width;
    int height = rpg->glib->window->mode.height;
    sfVector2f view_pos = sfView_getCenter(rpg->player->view->view);
    if (RPI->is_open != 1) return;

    sfRectangleShape_setPosition(RPI->background,
    (sfVector2f){view_pos.x - width / 2, view_pos.y - height / 2});
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window,
    RPI->background, NULL);
    sfSprite_setPosition(RP->inventory->items_data_sprite,
    (sfVector2f) {view_pos.x - 74, view_pos.y + 40});
    draw_items(rpg);
    handle_inventory_system(rpg);
}
