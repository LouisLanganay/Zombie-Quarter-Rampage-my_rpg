/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** swap_status_anim_cbt
*/

#include "rpg.h"

void swap_status_anim_cbt(zombies_t *l)
{
    if (l->status_anim == 0) {
        l->animation = 0;
        l->status_anim = 1;
    }
}
