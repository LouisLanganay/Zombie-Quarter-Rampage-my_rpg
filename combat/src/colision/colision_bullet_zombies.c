/*
** EPITECH PROJECT, 2023
** combat
** File description:
** colision_bullet_zombies
*/

#include "../../combat/includes/rpg.h"

int colision_bullet_zombies(zombies_t *list, bullets_t *bullets)
{
    zombies_t *tmp_zombie = list;
    bullets_t *tmp_bullet = bullets;
    if (tmp_zombie == NULL)
        return (0);
    if (tmp_bullet == NULL)
        return (0);
    int index_bullet = 0;
    while (tmp_zombie != NULL) {
        index_bullet = 0;
        tmp_bullet = bullets;
        while (tmp_bullet != NULL) {
            if (colision_with_rect(tmp_zombie->hitbox, tmp_bullet->pos) == 1) {
                tmp_zombie->hp -= 10;
                if (tmp_zombie->hp <= 0) {
                    delete_zombie(list, tmp_zombie);
                }
                tmp_bullet->status = 1;
                return (1);
            }
            index_bullet++;
            tmp_bullet = tmp_bullet->next;
        }
        tmp_zombie = tmp_zombie->next;
    }
    return (0);
}
