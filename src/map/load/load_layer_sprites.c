/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** load_layer_sprites
*/

#include "rpg.h"

sfSprite **load_layer_sprites(layer_t *layer, map_t *map)
{
    unsigned int data_texture = 0;
    sfSprite **sprites = malloc(sizeof(sfSprite *) *
        (layer->height * layer->width));

    for (int i = 0; i < layer->height * layer->width; i++) {
        sprites[i] = sfSprite_create();
        data_texture = layer->data[i];
        if (sprites[i] == NULL) continue;
        if (map->textures[data_texture] == NULL) continue;
        sfSprite_setTexture(sprites[i], map->textures[data_texture], sfTrue);
        sfSprite_setPosition(sprites[i], (sfVector2f){
            (i % layer->width) * map->tile_width,
            (i / layer->width) * map->tile_height
        });
    }

    return sprites;
}
