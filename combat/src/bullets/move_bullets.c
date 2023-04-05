/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** move_bullets
*/

#include "../../includes/rpg.h"
#include <math.h>
#define M_PI 3.14159265358979323846

void move_bullets(bullets_t *bullets)
{
    bullets_t *tmp = bullets;
    while (tmp != NULL) {
        tmp->pos.x += cos(tmp->angle * M_PI / 180) * tmp->speed;
        tmp->pos.y += sin(tmp->angle * M_PI / 180) * tmp->speed;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        tmp = tmp->next;
    }
}
