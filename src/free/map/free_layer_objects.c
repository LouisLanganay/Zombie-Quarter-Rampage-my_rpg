/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** free_layer_objects
*/

#include "rpg.h"

static void free_layer_object(tiled_object_t *tmp)
{
    free(tmp->name);
    free(tmp);
}

void free_layer_objects(tiled_object_t *tmp)
{
    tiled_object_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free_layer_object(tmp);
        tmp = next;
    }
}
