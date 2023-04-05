/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** delete_bullet
*/

#include "../../includes/rpg.h"

void delete_bullet(bullets_t **list, int index)
{
    bullets_t *tmp = *list;
    bullets_t *prev = NULL;
    int i = 0;
    if (tmp == NULL)
        return;
    if (index == 0) {
        if (tmp->next == NULL) {
            *list = tmp->next;
            free(tmp);
        }
        else {
            *list = tmp->next;
            free(tmp);
        }
        return;
    }
    while (tmp != NULL && i != index) {
        prev = tmp;
        tmp = tmp->next;
        i++;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
}