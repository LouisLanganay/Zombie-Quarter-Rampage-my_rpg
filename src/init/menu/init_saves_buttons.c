/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_saves_buttons
*/

#include "rpg.h"

static void init_saves_buttons_one(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_SAVE1;
    my_btn->pos = (sfVector2f){ rpg->glib->window->mode.width / 2.945,
    rpg->glib->window->mode.height / 8};
    my_btn->rect = (sfIntRect){0, 0, 591, 168};
    my_btn->call_action = e_save1;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_SAVE, NULL);
    my_btn->sb_hover = sfSoundBuffer_createFromFile(BTN_HOVER_SOUND);
    my_btn->sb_click = sfSoundBuffer_createFromFile(BTN_CLICK_SOUND);
    gl_create_button(rpg->glib, my_btn);
}

static void init_saves_buttons_two(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_SAVE2;
    my_btn->pos = (sfVector2f){ rpg->glib->window->mode.width / 2.945,
    rpg->glib->window->mode.height / 3.5};
    my_btn->rect = (sfIntRect){0, 0, 591, 168};
    my_btn->call_action = e_save2;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_SAVE, NULL);
    my_btn->sb_hover = sfSoundBuffer_createFromFile(BTN_HOVER_SOUND);
    my_btn->sb_click = sfSoundBuffer_createFromFile(BTN_CLICK_SOUND);
    gl_create_button(rpg->glib, my_btn);
}

static void init_saves_buttons_three(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_SAVE3;
    my_btn->pos = (sfVector2f){ rpg->glib->window->mode.width / 2.945,
    rpg->glib->window->mode.height / 2.2};
    my_btn->rect = (sfIntRect){0, 0, 591, 168};
    my_btn->call_action = e_save3;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_SAVE, NULL);
    my_btn->sb_hover = sfSoundBuffer_createFromFile(BTN_HOVER_SOUND);
    my_btn->sb_click = sfSoundBuffer_createFromFile(BTN_CLICK_SOUND);
    gl_create_button(rpg->glib, my_btn);
}

void init_saves_buttons(rpg_t *rpg)
{
    rpg->menu_save = malloc(sizeof(menu_save_t));
    sfImage *image = sfImage_createFromFile("resources/assets/gui/UI.png");
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    rpg->menu_save->bg_sprite = sfSprite_create();
    rpg->menu_save->active = false;

    sfSprite_setTexture(rpg->menu_save->bg_sprite, texture, sfTrue);
    sfSprite_setTextureRect(rpg->menu_save->bg_sprite,
        (sfIntRect){415, 0, 50, 64});
    sfSprite_setPosition(rpg->menu_save->bg_sprite,
    (sfVector2f){rpg->glib->window->mode.width / 3.35, -200});
    sfSprite_setScale(rpg->menu_save->bg_sprite, (sfVector2f){15, 15});
    init_saves_buttons_one(rpg);
    init_saves_buttons_two(rpg);
    init_saves_buttons_three(rpg);
}
