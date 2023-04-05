/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_keybinds.c
*/

#include "rpg.h"


void init_keybinds(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_KEYBIND;
    my_btn->pos = (sfVector2f){ rpg->glib->window->mode.width / 2.3, rpg->glib->window->mode.height / 1.4};
    my_btn->rect = (sfIntRect){0, 0, 278, 72};
    my_btn->call_action = e_seeting_keybinds_game;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_RESUME, NULL);
    my_btn->sb_hover = NULL;
    my_btn->sb_click = NULL;
    gl_create_button(rpg->glib, my_btn);
}

void init_settings_keybind(rpg_t *rpg)
{
    sfImage *image = sfImage_createFromFile("resources/assets/gui/UI.png");
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    rpg->menu_key->settings_bg_key_sprite = sfSprite_create();

    sfSprite_setTexture(rpg->menu_key->settings_bg_key_sprite, texture, sfTrue);
    sfSprite_setTextureRect(rpg->menu_key->settings_bg_key_sprite,
        (sfIntRect){415, 0, 50, 64});
    sfSprite_setPosition(rpg->menu_key->settings_bg_key_sprite, (sfVector2f){rpg->glib->window->mode.width / 1.4, rpg->glib->window->mode.height / 3.4});
    sfSprite_setScale(rpg->menu_key->settings_bg_key_sprite, (sfVector2f){10, 10});
}
