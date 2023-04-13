/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_hud
*/

#include "rpg.h"

static void draw_hud_hp(rpg_t *rpg, sfVector2f view_pos, sfVector2f view_size)
{
    sfRectangleShape_setSize(rpg->hud->hp_bar,
        (sfVector2f){((float)rpg->player->hp / 100) * 100, 4});

    sfRectangleShape_setPosition(rpg->hud->hp_bar_back, (sfVector2f){view_pos.x
        - view_size.x / 2 + 10 , view_pos.y + view_size.y / 2 - 16});
    sfRectangleShape_setPosition(rpg->hud->hp_bar, (sfVector2f){view_pos.x
        - view_size.x / 2 + 10 , view_pos.y + view_size.y / 2 - 16});
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window,
        rpg->hud->hp_bar_back, NULL);
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window,
        rpg->hud->hp_bar, NULL);
}

static void draw_hud_hunger(
    rpg_t *rpg,
    sfVector2f view_pos,
    sfVector2f view_size
)
{
    sfRectangleShape_setSize(rpg->hud->hunger_bar,
        (sfVector2f){((float)rpg->player->hunger / 100) * 100, 4});

    sfRectangleShape_setPosition(rpg->hud->hunger_bar_back,
    (sfVector2f){view_pos.x - view_size.x / 2 + 10,
    view_pos.y + view_size.y / 2 - 10});
    sfRectangleShape_setPosition(rpg->hud->hunger_bar, (sfVector2f){view_pos.x
        - view_size.x / 2 + 10 , view_pos.y + view_size.y / 2 - 10});
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window,
        rpg->hud->hunger_bar_back, NULL);
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window,
        rpg->hud->hunger_bar, NULL);
}

void draw_hud(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(rpg->player->view->view);
    sfVector2f view_size = sfView_getSize(rpg->player->view->view);

    draw_hud_hp(rpg, view_pos, view_size);
    draw_hud_hunger(rpg, view_pos, view_size);
}
