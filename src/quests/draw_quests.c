/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_quests
*/

#include "rpg.h"

void draw_quests(rpg_t *rpg)
{
    printf("QUESTs:\n");
    for (int i = 0; rpg->quests_in_progress[i]; i++)
        printf("\t%s\n", rpg->quests_in_progress[i]);
}
