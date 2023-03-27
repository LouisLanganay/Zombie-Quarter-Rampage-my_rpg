/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** load_tiles_textures
*/

#include "rpg.h"

static int tiles_count(map_t *map)
{
    tilesets_t *tmp = map->tilesets;
    int count = 0;

    while (tmp) {
        count += tmp->tile_count;
        tmp = tmp->next;
    }
    return count;
}

static int load_tiles_textures_tileset(
    tilesets_t *tmp,
    map_t *map,
    sfTexture **textures,
    int i
)
{
    sfTexture *tileset_texture = sfTexture_createFromFile(tmp->path, NULL);
    sfImage *tileset_image = sfTexture_copyToImage(tileset_texture);
    sfVector2u size = sfTexture_getSize(tileset_texture);
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    *rect = (sfIntRect){0, 0, map->tile_width, map->tile_height};
    for (int x = 1; x < tmp->tile_count; x++, i++) {
        printf("Texture %i %i\n", i, x);
        textures[i] = sfTexture_createFromImage(tileset_image, rect);
        if (rect->left + map->tile_width >= (int)size.x) {
            rect->left = 0;
            rect->top += map->tile_height;
        } else {
            rect->left += map->tile_width;
        }
    }
    i++;
    sfImage_destroy(tileset_image);
    sfTexture_destroy(tileset_texture);
    free(rect);
    return i;
}

sfTexture **load_tiles_textures(map_t *map)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * tiles_count(map));
    tilesets_t *tmp = map->tilesets;
    int i = 1;

    while (tmp) {
        i = load_tiles_textures_tileset(tmp, map, textures, i);
        tmp = tmp->next;
    }
    return textures;
}
