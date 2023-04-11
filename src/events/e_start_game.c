/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** e_start_game.c
*/

#include "rpg.h"

void e_start_game(int id, void *main)
{
    (void)(id);
    rpg_t *rpg = (rpg_t *)main;

    start_game(rpg);
}
