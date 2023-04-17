/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** e_key_pressed
*/

#include "rpg.h"

static void e_key_pressed_select(rpg_t *rpg)
{
    if (rpg->glib->window->event.key.code == sfKeyUp &&
    RPI->pos > 3)
        RPI->pos -= 4;

    if (rpg->glib->window->event.key.code == sfKeyLeft &&
    RPI->pos > 0)
        RPI->pos -= 1;

    if (rpg->glib->window->event.key.code == sfKeyRight &&
    RPI->pos < 15)
        RPI->pos += 1;

    if (rpg->glib->window->event.key.code == sfKeyDown &&
    RPI->pos < 12)
        RPI->pos += 4;

}

static void e_key_pressed_movement(rpg_t *rpg)
{
    if (rpg->glib->window->event.key.code == rpg->player->keys->up.key)
        rpg->player->keys->up.state = 1;
    if (rpg->glib->window->event.key.code == rpg->player->keys->down.key)
        rpg->player->keys->down.state = 1;
    if (rpg->glib->window->event.key.code == rpg->player->keys->left.key)
        rpg->player->keys->left.state = 1;
    if (rpg->glib->window->event.key.code == rpg->player->keys->right.key)
        rpg->player->keys->right.state = 1;
}

static void e_key_pressed_escape(rpg_t *rpg)
{
    rpg->menu_save->active = false;
    rpg->menu_key->active = false;
    rpg->menu->active = false;
    if (sfKeyboard_isKeyPressed(RPK->escape.key) == sfTrue
        && rpg->game_state == GAME || rpg->game_state == PAUSE) {
        if (rpg->player->inventory->is_open == 1 || rpg->player->lore_open == 1
        || rpg->player->in_dialogue == 1) return;
        rpg->game_state == PAUSE ?
            (rpg->game_state = GAME) : (rpg->game_state = PAUSE);
    }
}

void e_key_pressed(window_t *window, void *main)
{
    (void)window;
    rpg_t *rpg = (rpg_t *)main;
    e_key_pressed_movement(rpg);
    e_key_pressed_select(rpg);
    e_key_pressed_escape(rpg);
    if (rpg->glib->window->event.key.code == sfKeyF11)
        change_window_mode(rpg, rpg->settings->window_mode == FSCREEN ?
        WINDOWED : FSCREEN);
    if (rpg->glib->window->event.key.code == sfKeyB)
        save(rpg);
}
