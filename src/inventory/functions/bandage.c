/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** bandage
*/

#include "rpg.h"

void bandage(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    printf("You used a bandage\n");
    rpg->player->hp += 10;
    if (rpg->player->hp > 100)
        rpg->player->hp = 100;
    printf("Your hp is now %d\n", rpg->player->hp);
}
