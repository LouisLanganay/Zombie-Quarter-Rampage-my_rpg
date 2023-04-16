/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_saves_menu
*/

#include "rpg.h"

void draw_saves_menu(rpg_t *rpg)
{
    gl_button_change_state(BTN_SAVE1, rpg->glib->buttons, sfFalse);
    gl_button_change_state(BTN_SAVE2, rpg->glib->buttons, sfFalse);
    gl_button_change_state(BTN_SAVE3, rpg->glib->buttons, sfFalse);
    sfRenderWindow_drawSprite(rpg->glib->window->window,
        rpg->menu_save->bg_sprite, NULL);
    gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
    gl_draw_button(BTN_SAVE1, rpg->glib->buttons, rpg->glib->window);
    gl_draw_text(rpg->glib, TXT_SAVE1);
    gl_draw_button(BTN_SAVE2, rpg->glib->buttons, rpg->glib->window);
    gl_draw_text(rpg->glib, TXT_SAVE2);
    gl_draw_button(BTN_SAVE3, rpg->glib->buttons, rpg->glib->window);
    gl_draw_text(rpg->glib, TXT_SAVE3);
}
