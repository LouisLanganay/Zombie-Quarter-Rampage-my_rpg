/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** e_key_pressed
*/

#include "rpg.h"

void e_key_pressed(window_t *window, void *main)
{
    (void)window;
    rpg_t *rpg = (rpg_t *)main;
    if (rpg->glib->window->event.key.code == rpg->player->keys->up.key)
        rpg->player->keys->up.state = 1;
    if (rpg->glib->window->event.key.code == rpg->player->keys->down.key)
        rpg->player->keys->down.state = 1;
    if (rpg->glib->window->event.key.code == rpg->player->keys->left.key)
        rpg->player->keys->left.state = 1;
    if (rpg->glib->window->event.key.code == rpg->player->keys->right.key)
        rpg->player->keys->right.state = 1;
    if (rpg->glib->window->event.key.code == sfKeyB) {
        save_player(rpg);
        save_game(rpg);
    }
    if (rpg->glib->window->event.key.code == sfKeyI)
        add_item_to_inventory(70, rpg);
    if (rpg->glib->window->event.key.code == sfKeyM)
        remove_item_to_inventory(rpg, 5);
    if (rpg->glib->window->event.key.code == sfKeyL)
        add_item_to_inventory_pos(rpg, 5, 70);
    if (rpg->glib->window->event.key.code == sfKeyB)
        save(rpg);
}
