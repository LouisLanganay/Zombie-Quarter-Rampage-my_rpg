/*
** EPITECH PROJECT, 2023
** combat
** File description:
** delete_zombie
*/

#include "../../combat/includes/rpg.h"

void delete_zombie(zombies_t *list, zombies_t *node)
{
    zombies_t *tmp = list;
    zombies_t *prev = NULL;
    if (tmp == NULL)
        return;
    if (tmp == node) {
        if (tmp->next == NULL) {
            list = tmp->next;
            free(tmp);
        }
        else {
            list = tmp->next;
            free(tmp);
        }
        return;
    }
    while (tmp != NULL) {
        if (tmp == node) {
            if (prev == NULL) {
                list = tmp->next;
                free(tmp);
                return;
            }
            prev->next = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
