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
    save_quests_in_progress(rpg);
    printf("Food given\n");
}
