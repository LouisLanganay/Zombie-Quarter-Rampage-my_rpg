/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** swap_status_anim_move
*/

#include "rpg.h"

void swap_status_anim_move(zombies_t *l)
{
    if (l->status_anim == 1) {
        l->animation = 0;
        l->status_anim = 0;
    }
}
