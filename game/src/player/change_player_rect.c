/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** change_player_rect
*/

#include "rpg.h"

void change_player_rect(player_t *player)
{
    if (player->keys->up.state == 1) {
        player->rect.left = player->rect.width * 1;
    }
    if (player->keys->down.state == 1) {
        player->rect.left = 0;
    }
    if (player->keys->left.state == 1) {
        player->rect.left = player->rect.width * 3;
    }
    if (player->keys->right.state == 1) {
        player->rect.left = player->rect.width * 2;
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
}
