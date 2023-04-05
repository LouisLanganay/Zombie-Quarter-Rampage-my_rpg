/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_sprite
*/

#include "../gl.h"

static int gl_create_sprite_check_id(sprite_t *sprites, int id)
{
    sprite_t *tmp = sprites;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_sprite) Sprite id already exist\n", 43);
        tmp = tmp->next;
    }
    return (0);
}

int gl_create_sprite(GLib_t *glib, sprite_t *sprite)
{
    if (gl_create_sprite_check_id(glib->sprites, sprite->id) != 0)
        return (84);
    sprite_t *tmp = malloc(sizeof(*tmp));
    tmp->id = sprite->id;
    tmp->pos = sprite->pos;
    tmp->sprite = sprite->sprite;
    tmp->texture = sprite->texture;
    tmp->scale = sprite->scale;
    sfSprite_setPosition(tmp->sprite, tmp->pos);
    sfSprite_setScale(tmp->sprite, tmp->scale);
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    if (sprite->call_action != NULL)
        tmp->call_action = sprite->call_action;
    else
        tmp->call_action = NULL;

    tmp->next = glib->sprites;
    glib->sprites = tmp;
}
