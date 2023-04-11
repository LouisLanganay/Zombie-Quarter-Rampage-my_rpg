/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** divide_a_text
*/

#include "rpg.h"

void divide_a_text(rpg_t *rpg, devide_text_t *devide)
{
    int len = my_strlen(devide->text);
    int nb_text = len / devide->max_len + 1;
    sfText *new_text = NULL;

    for (int i = 0; i < nb_text; i++) {
        new_text = sfText_create();
        sfText_setFont(new_text, gl_get_font(rpg->glib, CRYSTAL_FONT));
        sfText_setCharacterSize(new_text, 134);
        sfText_setScale(new_text, (sfVector2f){0.05, 0.05});
        sfText_setString(new_text, my_strndup(devide->text, devide->max_len));
        sfText_setPosition(new_text,
            (sfVector2f){devide->pos.x, devide->pos.y + i * 10});
        sfText_setColor(new_text, devide->color);
        sfRenderWindow_drawText(rpg->glib->window->window, new_text, NULL);
        sfText_destroy(new_text);
        devide->text += devide->max_len;
    }
}
