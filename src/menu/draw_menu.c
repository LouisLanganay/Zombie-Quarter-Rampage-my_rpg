/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_menu.c
*/

#include "rpg.h"

void draw_menu(rpg_t *rpg) {
//QUIT
        gl_button_change_state(BTN_QUIT, rpg->glib->buttons, sfFalse);
        gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
        gl_draw_button(BTN_QUIT, rpg->glib->buttons, rpg->glib->window);
//START
        gl_button_change_state(BTN_START, rpg->glib->buttons, sfFalse);
        gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
        gl_draw_button(BTN_START, rpg->glib->buttons, rpg->glib->window);
//RESUME
        gl_button_change_state(BTN_RESUME, rpg->glib->buttons, sfFalse);
        gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
        gl_draw_button(BTN_RESUME, rpg->glib->buttons, rpg->glib->window);
//SEETING
        gl_button_change_state(BTN_SEETING, rpg->glib->buttons, sfFalse);
        gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
        gl_draw_button(BTN_SEETING, rpg->glib->buttons, rpg->glib->window);
//BG_SEETING and KEYBINDS BUTTON
        if (rpg->menu->active == true) {
                sfRenderWindow_drawSprite(rpg->glib->window->window, rpg->menu->settings_bg_sprite, NULL);
                gl_button_change_state(BTN_KEYBIND, rpg->glib->buttons, sfFalse);
                gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
                gl_draw_button(BTN_KEYBIND, rpg->glib->buttons, rpg->glib->window);
                sfRenderWindow_drawSprite(rpg->glib->window->window, rpg->menu_key->settings_bg_key_sprite, NULL);
        }

}
