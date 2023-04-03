/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_player
*/

#include "rpg.h"

static void init_player_hitbox(player_t *player)
{
    player->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(player->hitbox, (sfVector2f){
        PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT
    });
    sfRectangleShape_setFillColor(player->hitbox, sfRed);
    sfRectangleShape_setOrigin(player->hitbox, (sfVector2f){
        0, PLAYER_SPRITE_HEIGHT
    });
}

static void init_player_texture(player_t *player)
{
    player->texture = sfTexture_createFromFile(PLAYER_SPRITE_PATH, NULL);
    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->rect = (sfIntRect){0, 0, PLAYER_SPRITE_WIDTH, PLAYER_SPRITE_HEIGHT};
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setOrigin(player->sprite, (sfVector2f){0, PLAYER_SPRITE_HEIGHT});
}

static void init_player_keys(player_t *player)
{
    player->keys = malloc(sizeof(keys_t));
    player->keys->up = (p_key_t){0, sfKeyZ};
    player->keys->down = (p_key_t){0, sfKeyS};
    player->keys->left = (p_key_t){0, sfKeyQ};
    player->keys->right = (p_key_t){0, sfKeyD};
    player->keys->interact = (p_key_t){0, sfKeyE};
    player->keys->choice_one = (p_key_t){0, sfKeyU};
    player->keys->choice_two = (p_key_t){0, sfKeyI};
    player->keys->escape = (p_key_t){0, sfKeyEscape};
}

void init_player(rpg_t *rpg)
{
    player_t *player = malloc(sizeof(player_t));
    player->pos = (sfVector2f){SPAWN_X, SPAWN_Y};
    player->in_dialogue = 0;
    sfVector2f screen_size = (sfVector2f){
        rpg->glib->window->mode.width,
        rpg->glib->window->mode.height
    };
    player->view = init_view(screen_size, 0.3, 3);
    init_player_texture(player);
    init_player_keys(player);
    init_player_hitbox(player);
    init_player_assets(player);
    rpg->player = player;
}
