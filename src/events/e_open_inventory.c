/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** e_open_inventory
*/

#include "rpg.h"

static void handle_selection_inv(rpg_t *rpg)
{
    if (rpg->glib->window->event.key.code == sfKeyUp ||
    rpg->glib->window->event.key.code == sfKeyDown ||
    rpg->glib->window->event.key.code == sfKeyRight ||
    rpg->glib->window->event.key.code == sfKeyLeft)
        RPI->is_data_open = 1;
    if (sfKeyboard_isKeyPressed(rpg->player->keys->choice_one.key) == sfTrue
    && RPI->is_data_open == 0 && RPI->is_open == 1) {
        RPI->is_data_open = 1;
        remove_item_to_inventory(rpg, RP->inventory->pos, 0);
    }
    if (sfKeyboard_isKeyPressed(rpg->player->keys->choice_two.key) == sfTrue
    && RPI->is_data_open == 0 && RPI->is_open == 1) {
        RPI->is_data_open = 1;
        exec_item_func(rpg, RP->inventory->items[RP->inventory->pos]);
    }
}

void e_open_inventory(window_t *window, void *main)
{
    (void)window;
    rpg_t *rpg = (rpg_t *)main;

    if (sfKeyboard_isKeyPressed(rpg->player->keys->inventory.key) == sfTrue) {
        gl_play_sound(rpg->glib, INV_SOUND_ID);
        if (RPI->is_open == 0)
            RPI->is_open = 1;
        else
            RPI->is_open = 0;
    }
    if (sfKeyboard_isKeyPressed(rpg->player->keys->enter.key) == sfTrue) {
        if (RPI->is_data_open == 0)
            RPI->is_data_open = 1;
        else
            RPI->is_data_open = 0;
    }
    handle_selection_inv(rpg);
}
