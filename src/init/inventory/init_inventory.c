/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_inventory
*/

#include "rpg.h"

void init_inventory(rpg_t *rpg)
{
    int width = rpg->glib->window->mode.width;
    int height = rpg->glib->window->mode.height;

    rpg->player->inventory->background = sfRectangleShape_create();
    rpg->player->inventory->items_sprite = malloc(sizeof(sfSprite *) *
    INVENTORY_SIZE);
    rpg->player->inventory->bg_items_sprite = malloc(sizeof(sfSprite *) *
    INVENTORY_UI_SIZE);
    for (int i = 0; i < INVENTORY_SIZE; i++)
        rpg->player->inventory->items_sprite[i] = sfSprite_create();
    rpg->player->inventory->bg_items_sprite = sfSprite_create();
    sfRectangleShape_setSize(rpg->player->inventory->background, (sfVector2f)
    {width, height});
    sfRectangleShape_setFillColor(rpg->player->inventory->background, (sfColor)
    {0, 0, 0, 200});
}
