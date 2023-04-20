/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_player
*/

#include "rpg.h"

void cbt_draw_player(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->player->sprite, rpg->player->pos);
    cbt_change_player_rect(rpg->player);
    sfRectangleShape_setPosition(rpg->player->hitbox,
    (sfVector2f){rpg->player->pos.x, rpg->player->pos.y + 3});
    sfRenderWindow_drawSprite(rpg->glib->window->window,
    rpg->player->sprite, NULL);
    sfRectangleShape_setPosition(rpg->player->hp_bar,
    (sfVector2f){rpg->player->pos.x + 30 - rpg->player->hp / 2,
    rpg->player->pos.y - 135});
    sfRectangleShape_setSize(rpg->player->hp_bar,
    (sfVector2f){rpg->player->hp, 10});
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window,
    rpg->player->hp_bar, NULL);

}
