/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_items
*/

#include "rpg.h"

static void draw_ui(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(RP->view->view);
    sfVector2f items_pos = {view_pos.x - 74, view_pos.y - 101};

    sfSprite_setTexture(RP->inventory->bg_items_sprite,
    RP->assets->bg_items_texture, sfFalse);
    sfSprite_setPosition(RP->inventory->bg_items_sprite,
    items_pos);
    sfSprite_setScale(RP->inventory->bg_items_sprite,
    (sfVector2f) {2.2, 2.2});
    sfRenderWindow_drawSprite(rpg->glib->window->window,
    RP->inventory->bg_items_sprite, NULL);
}

void draw_items(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(RP->view->view);
    sfVector2f items_pos = {view_pos.x - 70, view_pos.y - 100};

    draw_ui(rpg);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        if (RP->inventory->items[i] >= 0 && RP->inventory->items[i] <= 114) {
            sfSprite_setTexture(RP->inventory->items_sprite[i],
            RP->assets->items_texture
            [RP->inventory->items[i]], sfFalse);
            sfSprite_setPosition(RP->inventory->items_sprite[i],
            items_pos);
            sfRenderWindow_drawSprite(rpg->glib->window->window,
            RP->inventory->items_sprite[i], NULL);
        }
        if ((i + 1) % 4 == 0) {
            items_pos.y += 35.3;
            items_pos.x = view_pos.x - 70;
        } else
            items_pos.x += 35.2;
    }
}
