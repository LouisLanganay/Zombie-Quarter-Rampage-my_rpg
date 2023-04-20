/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_escape_menu
*/

#include "rpg.h"

static void init_escape_menu_save(rpg_t *rpg)
{
    buttons_t *my_btn = malloc(sizeof(buttons_t));
    my_btn->id = BTN_SAVEBTN;
    my_btn->pos = (sfVector2f){rpg->glib->window->mode.width / 2.4,
    rpg->glib->window->mode.height / 1.65};
    my_btn->rect = (sfIntRect){0, 0, 278, 72};
    my_btn->call_action = e_save_btn;
    my_btn->sprite = sfSprite_create();
    my_btn->texture = sfTexture_createFromFile(BTN_PATH_SAVEBTN, NULL);
    my_btn->sb_hover = NULL;
    my_btn->sb_click = NULL;
    gl_create_button(rpg->glib, my_btn);
}

void init_escape_menu(rpg_t *rpg)
{
    init_escape_menu_save(rpg);
    gl_button_change_state(BTN_SAVEBTN, rpg->glib->buttons, sfTrue);
}
