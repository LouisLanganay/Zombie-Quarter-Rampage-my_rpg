/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_player_textures
*/

#include "rpg.h"

void init_player_textures(player_t *player)
{
    player->texture = sfTexture_createFromFile(PLAYER_SPRITE_PATH, NULL);
    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->rect = (sfIntRect){
        0, 0, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT
    };
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setOrigin(player->sprite, (sfVector2f){0, PLAYER_SPRITE_HEIGHT});
}
