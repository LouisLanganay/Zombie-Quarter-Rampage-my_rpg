/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_inventory
*/

#include "rpg.h"

static void init_inventory_sprite(rpg_t *rpg)
{
    rpg->player->inventory->select_sprite = sfSprite_create();
    rpg->player->assets->select_texture = sfTexture_createFromFile
    (PLAYER_INVENTORY_SELECT_PATH, NULL);
    rpg->player->inventory->items_data_sprite = sfSprite_create();
    rpg->player->assets->items_data_texture = sfTexture_createFromFile
    (PLAYER_ITEMS_DATA_PATH, NULL);
    sfSprite_setTexture(rpg->player->inventory->items_data_sprite,
    rpg->player->assets->items_data_texture, sfFalse);
    sfSprite_setTexture(rpg->player->inventory->select_sprite,
    rpg->player->assets->select_texture, sfFalse);
    sfSprite_setScale(rpg->player->inventory->select_sprite,
    (sfVector2f) {1.98, 1.98});
    for (int i = 0; i < INVENTORY_SIZE; i++)
        rpg->player->inventory->items_sprite[i] = sfSprite_create();
    rpg->player->inventory->bg_items_sprite = sfSprite_create();
}

void init_inventory(rpg_t *rpg)
{
    rpg->player->inventory->pos = 0;
    rpg->player->inventory->background = sfRectangleShape_create();
    rpg->player->inventory->items_sprite = malloc(sizeof(sfSprite *) *
    INVENTORY_SIZE);
    init_inventory_sprite(rpg);
    sfRectangleShape_setSize(rpg->player->inventory->background, (sfVector2f)
    {rpg->glib->window->mode.width, rpg->glib->window->mode.height});
    sfSprite_setScale(rpg->player->inventory->items_data_sprite, (sfVector2f)
    {3.15, 2});
    sfRectangleShape_setFillColor(rpg->player->inventory->background, (sfColor)
    {0, 0, 0, 200});
}
