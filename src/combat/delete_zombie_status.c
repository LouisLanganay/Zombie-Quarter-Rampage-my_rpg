/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** delete_zombie_status
*/

#include "rpg.h"

void delete_zombie_status(zombies_t **list)
{
    zombies_t *tmp = *list;
    zombies_t *prev = NULL;

    while (tmp != NULL && tmp->alive == 1) {
        *list = tmp->next;
        free(tmp);
        tmp = *list;
    }
    while (tmp != NULL) {
        while (tmp != NULL && tmp->alive == 0) {
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
