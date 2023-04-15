/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_main_menu.c
*/

#include "rpg.h"

static void init_main_menu_quit(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_QUIT;
    my_btn->pos = (sfVector2f){ rpg->glib->window->mode.width / 2.4,
    rpg->glib->window->mode.height / 1.65 + 50};
    my_btn->rect = (sfIntRect){0, 0, 278, 72};
    my_btn->call_action = e_quit;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_QUIT, NULL);
    my_btn->sb_hover = NULL;
    my_btn->sb_click = NULL;
    gl_create_button(rpg->glib, my_btn);
}

static void init_main_menu_start(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_START;
    my_btn->pos = (sfVector2f){ rpg->glib->window->mode.width / 7,
    rpg->glib->window->mode.height / 1.65};
    my_btn->rect = (sfIntRect){0, 0, 69.2, 72};
    my_btn->call_action = e_start_game;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_PLAY, NULL);
    my_btn->sb_hover = NULL;
    my_btn->sb_click = NULL;
    gl_create_button(rpg->glib, my_btn);
}

static void init_main_menu_resume(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_RESUME;
    my_btn->pos = (sfVector2f){rpg->glib->window->mode.width / 2.4,
    rpg->glib->window->mode.height / 1.3};
    my_btn->rect = (sfIntRect){0, 0, 278, 72};
    my_btn->call_action = e_resume_btn;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_RESUME, NULL);
    my_btn->sb_hover = NULL;
    my_btn->sb_click = NULL;
    gl_create_button(rpg->glib, my_btn);
}

static void init_main_menu_seeting(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_SEETING;
    my_btn->pos = (sfVector2f){rpg->glib->window->mode.width / 1.1,
    rpg->glib->window->mode.height / 2 - 500};
    my_btn->rect = (sfIntRect){0, 0, 69.2, 72};
    my_btn->call_action = e_seeting_game;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_OPTION, NULL);
    my_btn->sb_hover = NULL;
    my_btn->sb_click = NULL;
    gl_create_button(rpg->glib, my_btn);
}

void init_main_menu(rpg_t *rpg)
{
    rpg->menu = malloc(sizeof(menu_t));
    rpg->menu_key = malloc(sizeof(menu_t));
    rpg->background = malloc(sizeof(menu_background_t));
    init_background(rpg);
    init_buttons_langage(rpg);
    init_main_menu_quit(rpg);
    init_main_menu_start(rpg);
    init_main_menu_resume(rpg);
    init_main_menu_seeting(rpg);
    init_settings_menu(rpg);
    init_keybinds(rpg);
    init_saves_buttons(rpg);
    init_saves_texts(rpg);
    init_slider(rpg);
    init_escape_menu(rpg);
}
