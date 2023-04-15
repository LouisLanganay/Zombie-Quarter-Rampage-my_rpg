/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_inventory
*/

#include "rpg.h"

static void init_inventory_sprite(rpg_t *rpg)
{
    RPI->select_sprite = sfSprite_create();
    rpg->player->assets->select_texture = sfTexture_createFromFile
    (PLAYER_INVENTORY_SELECT_PATH, NULL);
    RPI->items_data_sprite = sfSprite_create();
    rpg->player->assets->items_data_texture = sfTexture_createFromFile
    (PLAYER_ITEMS_DATA_PATH, NULL);
    sfSprite_setTexture(RPI->items_data_sprite,
    rpg->player->assets->items_data_texture, sfFalse);
    sfSprite_setTexture(RPI->select_sprite,
    rpg->player->assets->select_texture, sfFalse);
    sfSprite_setScale(RPI->select_sprite,
    (sfVector2f) {1.98, 1.98});
    for (int i = 0; i < INVENTORY_SIZE; i++)
        RPI->items_sprite[i] = sfSprite_create();
    RPI->bg_items_sprite = sfSprite_create();
}

void init_inventory(rpg_t *rpg)
{
    RPI->pos = 0;
    RPI->background = sfRectangleShape_create();
    RPI->items_sprite = malloc(sizeof(sfSprite *) *
    INVENTORY_SIZE);
    init_inventory_sprite(rpg);
    sfRectangleShape_setSize(RPI->background, (sfVector2f)
    {rpg->glib->window->mode.width, rpg->glib->window->mode.height});
    sfSprite_setScale(RPI->items_data_sprite, (sfVector2f)
    {3.15, 2});
    sfRectangleShape_setFillColor(RPI->background, (sfColor)
    {0, 0, 0, 200});
    init_inventory_popup(rpg);
}
