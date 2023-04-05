/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** event_seetings.c
*/

#include "rpg.h"

void next_func()
{
    while (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue);
    return;
}

void e_seeting_game(int id, void *main)
{
    (void)(id);
    rpg_t *rpg = (rpg_t *)main;
        if (rpg->menu->active == false) {
            rpg->menu->active = true;
            next_func();
            return;
        }
        if (rpg->menu->active == true && rpg->menu_key->active == true) {
            rpg->menu->active = false;
            rpg->menu_key->active = false;
            next_func();
        }
        if (rpg->menu->active == true) {
        rpg->menu->active = false;
        next_func();
        }
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
