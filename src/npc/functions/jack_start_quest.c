/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** jack_start_quest
*/

#include "rpg.h"

void jack_start_quest(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    start_quest(rpg, "jack_quest");
}
