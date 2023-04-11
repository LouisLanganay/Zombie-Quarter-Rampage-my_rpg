/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_language.c
*/

#include "rpg.h"


static void init_main_menu_language(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_FRANCE;
    my_btn->pos = (sfVector2f){ rpg->glib->window->mode.width / 1.4,
    rpg->glib->window->mode.height / 1.3};
    my_btn->rect = (sfIntRect){0, 0, 278, 72};
    my_btn->call_action = NULL;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_FRANCE, NULL);
    my_btn->sb_hover = NULL;
    my_btn->sb_click = NULL;
    gl_create_button(rpg->glib, my_btn);
}
