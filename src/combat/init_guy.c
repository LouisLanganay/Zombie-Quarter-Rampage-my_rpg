/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_guy
*/

#include "rpg.h"

void init_guy(rpg_t *rpg)
{
    sprite_t *my_sprite = malloc(sizeof(sprite_t));
    my_sprite->id = 2;
    my_sprite->pos = (sfVector2f){200, 450};
    my_sprite->sprite = sfSprite_create();
    my_sprite->texture = sfTexture_createFromFile(guy, NULL);
    my_sprite->scale = (sfVector2f){1.5, 1.5};
    my_sprite->call_action = NULL;
    my_sprite->next = NULL;
    sfSprite_setOrigin(my_sprite->sprite, (sfVector2f){100, -20});
    gl_create_sprite(rpg->glib, my_sprite);
}
