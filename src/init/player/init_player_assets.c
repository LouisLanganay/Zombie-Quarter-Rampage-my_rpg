/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_player_assets
*/

#include "rpg.h"

static sfTexture **init_player_assets_keyboard(void)
{
    sfTexture *key_textures = sfTexture_createFromFile(PLAYER_KEYBOARD_PATH,
        NULL);
    sfImage *keyboard_image = sfTexture_copyToImage(key_textures);
    sfVector2u size = sfTexture_getSize(key_textures);
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    sfTexture **textures = malloc(sizeof(sfTexture *) * 112);
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
    sfSprite **sprites = malloc(sizeof(sfSprite *) * 112);

    for (int i = 0; i < 112; i++) {
        sprites[i] = sfSprite_create();
        sfSprite_setTexture(sprites[i], textures[i], sfTrue);
        sfSprite_setOrigin(sprites[i], (sfVector2f){8, 8});
    }
    return (sprites);
}

void init_player_assets(player_t *player)
{
    player->assets = malloc(sizeof(player_assets_t));
    player->assets->key_texture = init_player_assets_keyboard();
    player->assets->key_sprite = init_player_assets_keyboard_sprites(
        player->assets->key_texture);
}
