/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_npc
*/

#include "rpg.h"

npc_t *get_npc(map_t *map, char *name)
{
    npc_t *npc = map->npcs;

    while (npc) {
        if (my_strcmp(npc->name, name) == 0)
            return (npc);
        npc = npc->next;
    }
    return (NULL);
}
