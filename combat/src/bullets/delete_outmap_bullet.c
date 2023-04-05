/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** delete_outmap_bullet
*/

#include "../../includes/rpg.h"

void delete_outmap_bullet(bullets_t **bullets)
{
    bullets_t *tmp = *bullets;
    if (tmp == NULL)
        return;
    int i = 0;
    while (tmp != NULL) {
        if (tmp->pos.x > 1920 || tmp->pos.x < 0 || tmp->pos.y > 1080 || tmp->pos.y < 0) {
            delete_bullet(bullets, i);
            return;
        }
        tmp = tmp->next;
        i++;
    }
}
