/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** npc_give_food
*/

#include "rpg.h"

void npc_give_food(void *main)
{
    (void)(main);
    rpg_t *rpg = (rpg_t *)main;
    start_quest(rpg, "go_to_annia");
    start_quest(rpg, "test_quest");
    printf("Food given\n");
}
