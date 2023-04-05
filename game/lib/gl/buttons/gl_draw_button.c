/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_draw_button
*/

#include "../gl.h"

void gl_draw_button(int id, buttons_t *buttons, window_t *window)
{
    buttons_t *tmp = buttons;
    while (tmp != NULL) {
        if (tmp->id == id) {
            sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
            sfSprite_setTextureRect(tmp->sprite, tmp->rect);
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfRenderWindow_drawSprite(window->window, tmp->sprite, NULL);
            return;
        }
        tmp = tmp->next;
    }
    write(2, "(gl_draw_button) Button id not found\n", 37);
}
