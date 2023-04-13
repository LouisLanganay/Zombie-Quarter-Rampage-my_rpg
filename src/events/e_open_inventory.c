/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** e_open_inventory
*/

#include "rpg.h"

void e_open_inventory(window_t *window, void *main)
{
    (void)window;
    rpg_t *rpg = (rpg_t *)main;

    if (sfKeyboard_isKeyPressed(rpg->player->keys->inventory.key) == sfTrue) {
        if (rpg->player->inventory->is_open == 0)
            rpg->player->inventory->is_open = 1;
        else
            rpg->player->inventory->is_open = 0;
    }
    if (sfKeyboard_isKeyPressed(rpg->player->keys->enter.key) == sfTrue) {
        if (rpg->player->inventory->is_data_open == 0)
            rpg->player->inventory->is_data_open = 1;
        else
            rpg->player->inventory->is_data_open = 0;
    }
    if (rpg->glib->window->event.key.code == sfKeyUp ||
    rpg->glib->window->event.key.code == sfKeyDown ||
    rpg->glib->window->event.key.code == sfKeyRight ||
    rpg->glib->window->event.key.code == sfKeyLeft)
        rpg->player->inventory->is_data_open = 1;
    if (sfKeyboard_isKeyPressed(rpg->player->keys->choice_one.key) == sfTrue
    && rpg->player->inventory->is_data_open == 0) {
        rpg->player->inventory->is_data_open = 1;
        remove_item_to_inventory(rpg, RP->inventory->pos);
    }
}
