/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** remove_mask
*/

#include "rpg.h"

void remove_mask(void *main)
{
    rpg_t *rpg = (rpg_t *) main;

    remove_itemid_inventory(rpg, 31, 1);
    stop_quest(rpg, "jack_friend");
}
