/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_slider
*/

#include "rpg.h"

static void init_slider_text(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = SETTINGS_VOLUME_TEXT;
    my_text->pos = (sfVector2f){rpg->glib->window->mode.width / 2.4, 350};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "Volume";
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
}

void init_slider(rpg_t *rpg)
{
    rpg->menu->slider_texture = sfTexture_createFromFile(
        "resources/assets/buttons/slider.png", NULL);
    rpg->menu->slider_sprite = sfSprite_create();
    rpg->menu->slider_val = 10;
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f){300, 15});
    sfRectangleShape_setPosition(rect,
        (sfVector2f){rpg->glib->window->mode.width / 2.4, 400});
    sfRectangleShape_setFillColor(rect, sfWhite);
    rpg->menu->slider_back = rect;
    init_slider_text(rpg);
}
