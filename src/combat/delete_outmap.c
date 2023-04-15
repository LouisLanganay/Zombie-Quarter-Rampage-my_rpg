/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** delete_outmap
*/

#include "rpg.h"

void delete_bullet_outmap(bullets_t **list)
{
    bullets_t *tmp = *list;
    bullets_t *prev = NULL;

    while (tmp != NULL && tmp->pos.x > 1920) {
        *list = tmp->next;
        free(tmp);
        tmp = *list;
    }
    while (tmp != NULL) {
        while (tmp != NULL && tmp->pos.x < 1920) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp == NULL)
            return;
        prev->next = tmp->next;
        free(tmp);
        tmp = prev->next;
    }
}
