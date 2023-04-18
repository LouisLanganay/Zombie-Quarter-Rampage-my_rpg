/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** jackfriend_give_heal
*/

#include "rpg.h"

void jackfriend_give_heal(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    remove_itemid_inventory(rpg, 31);
    stop_quest(rpg, "jack_friend");
    add_item_to_inventory(82, rpg);
}
