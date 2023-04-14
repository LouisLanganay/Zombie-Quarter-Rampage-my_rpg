/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_player
*/

#include "rpg.h"

static void draw_player_hitbox(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(
        rpg->glib->window->window,
        rpg->player->hitbox, NULL);
}

void cbt_draw_player(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->player->sprite, rpg->player->pos);
    cbt_change_player_rect(rpg->player);
    sfRectangleShape_setPosition(rpg->player->hitbox,
    (sfVector2f){rpg->player->pos.x, rpg->player->pos.y + 3});
    sfRenderWindow_drawSprite(rpg->glib->window->window,
    rpg->player->sprite, NULL);
}
