/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_main_menu.c
*/

#include "rpg.h"

void init_main_menu(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_RESUME;
    my_btn->pos = (sfVector2f){50, 100};
    my_btn->rect = (sfIntRect){0, 0, 278, 72};
    my_btn->call_action = e_start_game;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_RESUME, NULL);
    my_btn->sb_hover = NULL;
    my_btn->sb_click = NULL;
    gl_create_button(rpg->glib, my_btn);
}
