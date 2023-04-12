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

void draw_player(rpg_t *rpg)
{
    if (rpg->player->in_dialogue != 1)
        check_player_moovment(rpg->player, get_map(rpg, rpg->actual_map), rpg);
    sfSprite_setPosition(rpg->player->sprite, rpg->player->pos);
    change_player_rect(rpg->player);
    sfRectangleShape_setPosition(
        rpg->player->hitbox,
        (sfVector2f){rpg->player->pos.x, rpg->player->pos.y + 3});
    if (rpg->debug)
        draw_player_hitbox(rpg);
    sfRenderWindow_drawSprite(
        rpg->glib->window->window,
        rpg->player->sprite, NULL);
}
