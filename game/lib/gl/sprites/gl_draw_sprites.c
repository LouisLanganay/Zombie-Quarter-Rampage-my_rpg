/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_sprites
*/

#include "../gl.h"

void gl_draw_sprites(GLib_t *glib)
{
    sprite_t *tmp = glib->sprites;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(glib->window->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}
