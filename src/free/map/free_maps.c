/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** free_maps
*/

#include "rpg.h"

void free_maps(rpg_t *rpg)
{
    map_t *tmp = rpg->maps;
    map_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free_map(tmp);
        tmp = next;
    }
}
