/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_menu.c
*/

#include "rpg.h"

static void draw_check_buttons(rpg_t *rpg)
{
    gl_draw_button(BTN_CHECK1, rpg->glib->buttons, rpg->glib->window);
    gl_draw_button(BTN_CHECK2, rpg->glib->buttons, rpg->glib->window);

    if (rpg->settings->game_language == FR) {
        gl_button_change_state(BTN_CHECK2, rpg->glib->buttons, sfFalse);
        gl_button_change_state(BTN_CHECK1, rpg->glib->buttons, sfTrue);
        return;
    }
    if (rpg->settings->game_language == EN) {
        gl_button_change_state(BTN_CHECK1, rpg->glib->buttons, sfFalse);
        gl_button_change_state(BTN_CHECK2, rpg->glib->buttons, sfTrue);
    }
    return;
}

static void draw_conditions_buttons(rpg_t *rpg)
{

    if (rpg->menu->active == false) {
        gl_button_change_state(BTN_QUIT, rpg->glib->buttons, sfFalse);
        gl_button_change_state(BTN_RESUME, rpg->glib->buttons, sfFalse);
        gl_button_change_state(BTN_START, rpg->glib->buttons, sfFalse);
        gl_button_change_state(BTN_KEYBIND, rpg->glib->buttons, sfTrue);
        gl_button_change_state(BTN_CHECK1, rpg->glib->buttons, sfFalse);
        gl_button_change_state(BTN_CHECK2, rpg->glib->buttons, sfFalse);
    }
    if (rpg->menu_key->active == true) {
        sfRenderWindow_drawSprite(rpg->glib->window->window,
        rpg->menu_key->settings_bg_key_sprite, NULL);
        draw_menu_keys(rpg);
    }
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
            gl_draw_text(rpg->glib, BTN_FRANCE);
            gl_draw_text(rpg->glib, BTN_ANGLAIS);
            draw_check_buttons(rpg);
    }
    draw_conditions_buttons(rpg);
}

static void disable_saves_menu(rpg_t *rpg)
{
    gl_button_change_state(BTN_SAVE1, rpg->glib->buttons, sfTrue);
    gl_button_change_state(BTN_SAVE2, rpg->glib->buttons, sfTrue);
    gl_button_change_state(BTN_SAVE3, rpg->glib->buttons, sfTrue);

}

void draw_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->glib->window->window,
    rpg->background->background_menu_s, NULL);
    if (rpg->menu->active == false) {
            gl_draw_button(BTN_QUIT, rpg->glib->buttons, rpg->glib->window);
            gl_draw_button(BTN_START, rpg->glib->buttons,rpg->glib->window);
            gl_draw_button(BTN_RESUME, rpg->glib->buttons,
            rpg->glib->window);
    }
    gl_draw_button(BTN_SEETING, rpg->glib->buttons, rpg->glib->window);
    if (rpg->menu_save->active == true)
        draw_saves_menu(rpg);
    else
        disable_saves_menu(rpg);
    draw_buttons(rpg);
    if (rpg->menu->active == true)
        draw_settings(rpg);
}
