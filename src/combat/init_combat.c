/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_combat
*/

#include "rpg.h"

combat_t *init_combat(void)
{
    combat_t *combat = malloc(sizeof(combat_t));
    combat->clock_move = sfClock_create();
    combat->clock_shoot = sfClock_create();
    combat->zombies = NULL;
    combat->bullets = NULL;
}
