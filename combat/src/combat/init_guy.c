/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_guy
*/

#include "../../includes/rpg.h"

void init_guy(rpg_t *rpg)
{
    sprite_t *my_sprite = malloc(sizeof(sprite_t));
    my_sprite->id = 2;
    my_sprite->pos = (sfVector2f){0, 500};
    my_sprite->sprite = sfSprite_create();
    my_sprite->texture = sfTexture_createFromFile("assets/guy.png", NULL);
    my_sprite->scale = (sfVector2f){1.25, 1.35};
    my_sprite->call_action = NULL;
    gl_create_sprite(rpg->glib, my_sprite);
}
