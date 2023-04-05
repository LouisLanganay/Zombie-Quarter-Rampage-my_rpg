/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_delete_sprite
*/

#include "../gl.h"

static void gl_delete_sprite_id(sprite_t *prev, sprite_t *tmp, GLib_t *glib)
{
    sfSprite_destroy(tmp->sprite);
    sfTexture_destroy(tmp->texture);
    if (prev == NULL)
        glib->sprites = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp);
}

void gl_delete_sprite(GLib_t *glib, int id)
{
    sprite_t *tmp = glib->sprites;
    sprite_t *prev = NULL;
    while (tmp != NULL) {
        if (tmp->id == id)
            return gl_delete_sprite_id(prev, tmp, glib);
        prev = tmp;
        tmp = tmp->next;
    }
}
