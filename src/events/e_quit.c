/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** e_quit.c
*/
#include "rpg.h"

void e_quit(int id, void *main)
{
    (void)id;
    rpg_t *rpg = (rpg_t *)main;
    sfRenderWindow_close(rpg->glib->window->window);
}
