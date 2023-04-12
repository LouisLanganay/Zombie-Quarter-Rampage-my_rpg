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
    player->keys->inventory = (p_key_t){0, sfKeyA};
    player->keys->enter = (p_key_t){0, sfKeyEnter};
    player->keys->last_direction = UP;
}

static void init_player_inventory(player_t *player)
{
    player->inventory = malloc(sizeof(inventory_t));
    player->inventory->items = malloc(sizeof(int) * 16);

    for (int i = 0; i < 16; i++)
        player->inventory->items[i] = -1;
    player->inventory->is_open = 0;
    player->inventory->is_data_open = 1;
    player->keys->escape = (p_key_t){0, sfKeyEscape};
    player->keys->last_direction = DOWN;
}

void init_player(rpg_t *rpg)
{
    player_t *player = malloc(sizeof(player_t));
    player->clock = sfClock_create();
    player->pos = (sfVector2f){SPAWN_X, SPAWN_Y};
    player->in_dialogue = 0;
    player->lore_open = 0;
    sfVector2f screen_size = (sfVector2f){
        rpg->glib->window->mode.width,
        rpg->glib->window->mode.height
    };
    player->view = init_view(screen_size, 0.3, 3);
    init_player_assets(player);
    init_player_textures(player);
    init_player_keys(player);
    init_player_hitbox(player);
    init_player_inventory(player);
    init_player_items_packs(player);
    rpg->player = player;
}
