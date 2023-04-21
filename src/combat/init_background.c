/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_background
*/

#include "rpg.h"

void init_background(rpg_t *rpg)
{
    sprite_t *my_sprite = malloc(sizeof(sprite_t));
    my_sprite->id = 1;
    my_sprite->pos = (sfVector2f){0, 0};
    my_sprite->sprite = sfSprite_create();
    my_sprite->texture = sfTexture_createFromFile(map_night, NULL);
    my_sprite->scale = (sfVector2f){1.25, 1.45};
    my_sprite->call_action = NULL;
    gl_create_sprite(rpg->glib, my_sprite);
}
