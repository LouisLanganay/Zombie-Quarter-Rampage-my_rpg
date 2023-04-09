/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** e_settings_key
*/

#include "rpg.h"

static void next_func(void)
{
    while (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue);
    return;
}

void e_seeting_keybinds_game(int id, void *main)
{
    (void)(id);
    rpg_t *rpg = (rpg_t *)main;
    if (rpg->menu_key->active == false) {
        rpg->menu_key->active = true;
        next_func();
        return;
    }
    if (rpg->menu_key->active == true) {
        rpg->menu_key->active = false;
        next_func();
    }
    return;
}
