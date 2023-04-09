/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_menu.c
*/

#include "rpg.h"

static void draw_conditions_buttons(rpg_t *rpg)
{
        if (rpg->menu->active == false) {
                gl_button_change_state(BTN_QUIT, rpg->glib->buttons, sfFalse);
                gl_button_change_state(BTN_RESUME, rpg->glib->buttons, sfFalse);
                gl_button_change_state(BTN_START, rpg->glib->buttons, sfFalse);
                gl_button_change_state(BTN_KEYBIND, rpg->glib->buttons, sfTrue);
        }
        if (rpg->menu_key->active == true)
                sfRenderWindow_drawSprite(rpg->glib->window->window,
                rpg->menu_key->settings_bg_key_sprite, NULL);
}

static void draw_buttons(rpg_t *rpg)
{
        if (rpg->menu->active == true) {
                gl_button_change_state(BTN_QUIT, rpg->glib->buttons, sfTrue);
                gl_button_change_state(BTN_RESUME, rpg->glib->buttons, sfTrue);
                gl_button_change_state(BTN_START, rpg->glib->buttons, sfTrue);
                sfRenderWindow_drawSprite(rpg->glib->window->window,
                rpg->menu->settings_bg_sprite, NULL);
                gl_button_change_state(BTN_KEYBIND,
                rpg->glib->buttons, sfFalse);
                gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
                gl_draw_button(BTN_KEYBIND, rpg->glib->buttons,
                rpg->glib->window);
        }
        draw_conditions_buttons(rpg);
}

void draw_menu(rpg_t *rpg)
{
        if (rpg->menu->active == false) {
                gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
                gl_draw_button(BTN_QUIT, rpg->glib->buttons, rpg->glib->window);
                gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
                gl_draw_button(BTN_START, rpg->glib->buttons,rpg->glib->window);
                gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
                gl_draw_button(BTN_RESUME, rpg->glib->buttons,
                rpg->glib->window);
        }
        gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
        gl_draw_button(BTN_SEETING, rpg->glib->buttons, rpg->glib->window);
        draw_buttons(rpg);
}
