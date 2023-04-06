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

    if (sfKeyboard_isKeyPressed(rpg->player->keys->inventory.key) == sfFalse)
        return;
    if (rpg->player->inventory->is_open == 0)
        rpg->player->inventory->is_open = 1;
    else
        rpg->player->inventory->is_open = 0;
}
