/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** jackfriend_give_weapon
*/

#include "rpg.h"

void jackfriend_give_weapon(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    add_item_to_inventory(74, rpg);
}
