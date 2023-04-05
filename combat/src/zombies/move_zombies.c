/*
** EPITECH PROJECT, 2023
** combat
** File description:
** move_zombies
*/

#include "../../combat/includes/rpg.h"

void move_zombies(zombies_t *list, rpg_t *rpg)
{
    zombies_t *tmp = list;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        tmp->pos.x -= tmp->speed;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfRectangleShape_move(tmp->hitbox, (sfVector2f){-tmp->speed, 0});
        tmp = tmp->next;
    }
}
