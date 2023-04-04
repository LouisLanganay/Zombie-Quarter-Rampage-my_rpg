/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_inventory_asset
*/

#include "rpg.h"

static sfTexture **init_inventory_assets_objects(void)
{
    sfTexture *items_texture = sfTexture_createFromFile(PLAYER_INVENTORY_PATH,
        NULL);
    sfImage *items_image = sfTexture_copyToImage(items_texture);
    sfVector2u size = sfTexture_getSize(items_texture);
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    sfTexture **textures = malloc(sizeof(sfTexture *) * 112);
    *rect = (sfIntRect){0, 0, 24, 24};

    for (int i = 0; i < 112; i++) {
        textures[i] = sfTexture_createFromImage(items_image, rect);
        if (rect->left + 24 >= (int)size.x) {
            rect->left = 0;
            rect->top += 24;
        } else
            rect->left += 24;
    }
    sfImage_destroy(items_image);
    sfTexture_destroy(items_texture);
    free(rect);
    return (textures);
}

void init_player_items_packs(player_t *player)
{
    player->assets = malloc(sizeof(player_assets_t));
    player->assets->items_texture = init_inventory_assets_objects();
}

