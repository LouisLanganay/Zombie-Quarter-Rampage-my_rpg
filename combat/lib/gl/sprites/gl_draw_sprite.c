/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_sprite_id
*/

#include "../gl.h"

void gl_draw_sprite(GLib_t *glib, int id)
{
    sprite_t *tmp = glib->sprites;
    while (tmp != NULL) {
        if (tmp->id == id) {
            sfRenderWindow_drawSprite(glib->window->window, tmp->sprite, NULL);
            return;
        }
        tmp = tmp->next;
    }
}
