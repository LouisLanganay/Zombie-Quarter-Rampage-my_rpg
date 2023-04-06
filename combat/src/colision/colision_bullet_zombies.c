/*
** EPITECH PROJECT, 2023
** combat
** File description:
** colision_bullet_zombies
*/

#include "../../combat/includes/rpg.h"

static int step_hit_zombie(zombies_t *tmp_zombie, bullets_t *tmp_bullet, int index_bullet)
{
    if (colision_with_rect(tmp_zombie->hitbox, tmp_bullet->pos) == 1) {
        tmp_zombie->hp -= 10;
        if (tmp_zombie->hp <= 0) {
            tmp_zombie->alive = 1;
        }
        tmp_bullet->status = 1;
        return (1);
    }
    index_bullet++;
    return (0);
}

static int loop_zombies(zombies_t *tmp_zombie, bullets_t *tmp_bullet, int index_bullet)
{
    while (tmp_bullet != NULL) {
        if (step_hit_zombie(tmp_zombie, tmp_bullet, index_bullet) == 1)
            return (index_bullet);
        tmp_bullet = tmp_bullet->next;
    }
    return (-1);
}

int colision_bullet_zombies(zombies_t *list, bullets_t *bullets)
{
    zombies_t *tmp_zombie = list;
    bullets_t *tmp_bullet = bullets;
    int value = 0;
    if (tmp_zombie == NULL)
        return (0);
    if (tmp_bullet == NULL)
        return (0);
    int index_bullet = 0;
    while (tmp_zombie != NULL) {
        index_bullet = 0;
        tmp_bullet = bullets;
        value = loop_zombies(tmp_zombie, tmp_bullet, index_bullet);
        if (value != -1)
            return (value);
        tmp_zombie = tmp_zombie->next;
    }
    return (0);
}
