/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_player_assets
*/

#include "rpg.h"

static void init_player_assets_keyboard_extra(player_assets_t *assets)
{
    sfTexture *key_textures = sfTexture_createFromFile(PLAYER_KEYBOARD_PATH2,
        NULL);
    sfImage *keyboard_image = sfTexture_copyToImage(key_textures);
    sfVector2u size = sfTexture_getSize(key_textures);
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    *rect = (sfIntRect){0, 0, 32, 16};

    for (int i = 112; i < 144; i++) {
        assets->key_texture[i] = sfTexture_createFromImage(keyboard_image,rect);
        if (rect->left + 32 >= (int)size.x) {
            rect->left = 0;
            rect->top += 16;
        } else
            rect->left += 32;
    }
    sfImage_destroy(keyboard_image);
    sfTexture_destroy(key_textures);
    free(rect);
}

static sfTexture **init_player_assets_keyboard(void)
{
    sfTexture *key_textures = sfTexture_createFromFile(PLAYER_KEYBOARD_PATH,
        NULL);
    sfImage *keyboard_image = sfTexture_copyToImage(key_textures);
    sfVector2u size = sfTexture_getSize(key_textures);
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    sfTexture **textures = malloc(sizeof(sfTexture *) * 144);
    *rect = (sfIntRect){0, 0, 16, 16};

    for (int i = 0; i < 112; i++) {
        textures[i] = sfTexture_createFromImage(keyboard_image, rect);
        if (rect->left + 16 >= (int)size.x) {
            rect->left = 0;
            rect->top += 16;
        } else
            rect->left += 16;
    }
    sfImage_destroy(keyboard_image);
    sfTexture_destroy(key_textures);
    free(rect);
    return (textures);
}

static sfSprite **init_player_assets_keyboard_sprites(sfTexture **textures)
{
    sfSprite **sprites = malloc(sizeof(sfSprite *) * 144);
    for (int i = 0; i < 144; i++) {
        sprites[i] = sfSprite_create();
        sfSprite_setTexture(sprites[i], textures[i], sfTrue);
        if (i < 112)
            sfSprite_setOrigin(sprites[i], (sfVector2f){8, 8});
        else
            sfSprite_setOrigin(sprites[i], (sfVector2f){16, 8});
    }
    return (sprites);
}

void init_player_assets(player_t *player)
{
    player->assets = malloc(sizeof(player_assets_t));
    player->assets->clock = sfClock_create();
    player->assets->key_texture = init_player_assets_keyboard();
    init_player_assets_keyboard_extra(player->assets);
    PA->key_sprite = init_player_assets_keyboard_sprites(PA->key_texture);
    PA->key_choice1 = init_player_assets_keyboard_sprites(PA->key_texture);
    PA->key_choice2 = init_player_assets_keyboard_sprites(PA->key_texture);
    init_player_assets_dialogue(player);
}
