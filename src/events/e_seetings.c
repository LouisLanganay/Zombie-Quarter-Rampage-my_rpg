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
            printf("%s\n","true");
            next_func();
            return;
        }
        if (rpg->menu->active == true) {
        rpg->menu->active = false;
        printf("%s\n","fals");
        next_func();
        }
    return;
}
