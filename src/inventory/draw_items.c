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
    sfVector2f items_pos = {view_pos.x - 70, view_pos.y - 100};

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        sfSprite_setTexture(rpg->player->inventory->items_sprite[i],
        rpg->player->assets->items_texture[i], sfFalse);
        sfSprite_setPosition(rpg->player->inventory->items_sprite[i], items_pos);
        if ((i + 1) % 4 == 0) {
            items_pos.y += 28;
            items_pos.x = view_pos.x - 70;
        } else
            items_pos.x += 28;
        sfRenderWindow_drawSprite(rpg->glib->window->window,
        rpg->player->inventory->items_sprite[i], NULL);
    }
}
