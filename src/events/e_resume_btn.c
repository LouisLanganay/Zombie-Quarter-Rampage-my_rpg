/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** e_resume_btn
*/

#include "rpg.h"

static void next_func(void)
{
    while (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue);
    return;
}

void e_resume_btn(int id, void *main)
{
    (void)id;
    rpg_t *rpg = (rpg_t *)main;
    rpg->menu_save->active = (rpg->menu_save->active == true) ? false : true;
    next_func();
}
