/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** bullet_manager
*/

#include "rpg.h"

void delete_bullet_status(bullets_t **list)
{
    bullets_t *tmp = *list;
    bullets_t *prev = NULL;

    while (tmp != NULL && tmp->status == 1) {
        *list = tmp->next;
        free(tmp);
        tmp = *list;
    }
    while (tmp != NULL) {
        while (tmp != NULL && tmp->status == 0) {
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
