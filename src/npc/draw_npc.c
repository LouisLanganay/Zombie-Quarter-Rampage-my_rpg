/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_npc
*/

#include "rpg.h"

static void change_npc_rect_annimate(npc_t *npc)
{
    time_t time = sfClock_getElapsedTime(npc->clock).microseconds;
    float seconds = time / 1000000.0;
    if (seconds < 0.30) return;
    npc->rect.top += PLAYER_SPRITE_HEIGHT;
    if (npc->rect.top >= PLAYER_SPRITE_HEIGHT * 6)
        npc->rect.top = 0;
    sfClock_restart(npc->clock);
}

void draw_npc(rpg_t *rpg, npc_t *npc)
{
    change_npc_rect_annimate(npc);
    sfSprite_setTextureRect(npc->sprite, npc->rect);
    sfRenderWindow_drawSprite(RGW->window, npc->sprite, NULL);
}
