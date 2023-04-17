/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_language.c
*/
#include "rpg.h"

static void init_main_menu_fr(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = BTN_FRANCE;
    my_text->pos = (sfVector2f){850, 600};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = (sfColor){250, 250, 250, 255};
    my_text->string = "Francais";
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
}

static void init_main_menu_en(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = BTN_ANGLAIS;
    my_text->pos = (sfVector2f){850, 700};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = (sfColor){250, 250, 250, 255};
    my_text->string = "English";
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
}

static void init_button_fr(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_CHECK1;
    my_btn->pos = (sfVector2f){ rpg->glib->window->mode.width / 1.9,
    rpg->glib->window->mode.height / 1.85};
    my_btn->rect = (sfIntRect){0, 0, 72, 72};
    my_btn->call_action = e_langue_fr;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_CHECK, NULL);
    my_btn->sb_hover = sfSoundBuffer_createFromFile(BTN_HOVER_SOUND);
    my_btn->sb_click = sfSoundBuffer_createFromFile(BTN_CLICK_SOUND);
    gl_create_button(rpg->glib, my_btn);
}

static void init_button_en(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_CHECK2;
    my_btn->pos = (sfVector2f){ rpg->glib->window->mode.width / 1.9,
    rpg->glib->window->mode.height / 1.6};
    my_btn->rect = (sfIntRect){0, 0, 72, 72};
    my_btn->call_action = e_langue_en;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_CHECK, NULL);
    my_btn->sb_hover = sfSoundBuffer_createFromFile(BTN_HOVER_SOUND);
    my_btn->sb_click = sfSoundBuffer_createFromFile(BTN_CLICK_SOUND);
    gl_create_button(rpg->glib, my_btn);
}

void init_buttons_langage(rpg_t *rpg)
{
    init_main_menu_fr(rpg);
    init_main_menu_en(rpg);
    init_button_fr(rpg);
    init_button_en(rpg);
}
