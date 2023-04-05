/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_npc
*/

#include "rpg.h"

void draw_npcs(map_t *map, rpg_t *rpg)
{
    npc_t *npc = map->npcs;

    while (npc) {
        sfRenderWindow_drawSprite(RGW->window, npc->sprite, NULL);
        npc = npc->next;
    }
}
