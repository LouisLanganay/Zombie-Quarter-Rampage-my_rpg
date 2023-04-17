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
    stop_quest(rpg, "go_to_annia");
    remove_itemid_inventory(rpg, 64);
    add_item_to_inventory(72, rpg);
}
