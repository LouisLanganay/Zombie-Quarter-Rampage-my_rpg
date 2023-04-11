/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_settings_menu.c
*/

#include "rpg.h"

void init_settings_menu(rpg_t *rpg)
{
    sfImage *image = sfImage_createFromFile("resources/assets/gui/UI.png");
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    rpg->menu->settings_bg_sprite = sfSprite_create();
    rpg->menu->active = false;

    sfSprite_setTexture(rpg->menu->settings_bg_sprite, texture, sfTrue);
    sfSprite_setTextureRect(rpg->menu->settings_bg_sprite,
        (sfIntRect){415, 0, 50, 64});
    sfSprite_setPosition(rpg->menu->settings_bg_sprite,
    (sfVector2f){rpg->glib->window->mode.width / 3.2, 1});
    sfSprite_setScale(rpg->menu->settings_bg_sprite, (sfVector2f){15, 15});
}
