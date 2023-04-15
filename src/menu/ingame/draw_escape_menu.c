/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_escape_menu
*/

#include "rpg.h"

static void draw_escape_menu_btn(rpg_t *rpg)
{
    gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
    gl_draw_button(BTN_SAVEBTN, rpg->glib->buttons, rpg->glib->window);
}

void draw_escape_menu(rpg_t *rpg)
{
    gl_button_change_state(BTN_SAVEBTN, rpg->glib->buttons, sfFalse);
    draw_escape_menu_btn(rpg);
}
