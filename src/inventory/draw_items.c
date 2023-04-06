/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_items
*/

#include "rpg.h"

static void draw_ui(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(rpg->player->view);
    sfVector2f items_pos = {view_pos.x - 74, view_pos.y - 101};

    sfSprite_setTexture(rpg->player->inventory->bg_items_sprite,
    rpg->player->assets->bg_items_texture, sfFalse);
    sfSprite_setPosition(rpg->player->inventory->bg_items_sprite,
    items_pos);
    sfSprite_setScale(rpg->player->inventory->bg_items_sprite,
    (sfVector2f) {2.2, 2.2});
    sfRenderWindow_drawSprite(rpg->glib->window->window,
    rpg->player->inventory->bg_items_sprite, NULL);
}

void draw_items(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(rpg->player->view);
    sfVector2f items_pos = {view_pos.x - 70, view_pos.y - 100};

    draw_ui(rpg);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        sfSprite_setTexture(rpg->player->inventory->items_sprite[i],
        rpg->player->assets->items_texture[i], sfFalse);
        sfSprite_setPosition(rpg->player->inventory->items_sprite[i],
        items_pos);
        if ((i + 1) % 4 == 0) {
            items_pos.y += 35.3;
            items_pos.x = view_pos.x - 70;
        } else
            items_pos.x += 35.2;
        sfRenderWindow_drawSprite(rpg->glib->window->window,
        rpg->player->inventory->items_sprite[i], NULL);
    }
}
