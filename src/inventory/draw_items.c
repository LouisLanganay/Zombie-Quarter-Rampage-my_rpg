/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_items
*/

#include "rpg.h"

void draw_items(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(rpg->player->view);
    sfVector2f items_pos = {view_pos.x - 400 / 2, view_pos.y - 200 / 2};

    for (int i = 0; i < NB_ITEMS; i++) {
        sfSprite_setTexture(rpg->player->inventory->items_sprite[i],
        rpg->player->assets->items_texture[i], sfFalse);
        if (items_pos.x > view_pos.x + 400 / 2) {
            items_pos.y += 24;
            items_pos.x = items_pos.x - 400 / 2;
        } else
            items_pos.x += 28;
        sfSprite_setPosition(rpg->player->inventory->items_sprite[i], items_pos);
        sfRenderWindow_drawSprite(rpg->glib->window->window,
        rpg->player->inventory->items_sprite[i], NULL);
    }
}
