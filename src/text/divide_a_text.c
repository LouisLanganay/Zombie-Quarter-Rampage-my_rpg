/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** divide_a_text
*/

#include "rpg.h"

void divide_a_text(rpg_t *rpg, char *str, sfVector2f pos, sfColor color)
{
    int len = my_strlen(str);
    int nb_text = len / 48 + 1;
    sfText *new_text = NULL;


    for (int i = 0; i < nb_text; i++) {
        new_text = sfText_create();
        sfText_setFont(new_text, gl_get_font(rpg->glib, CRYSTAL_FONT));
        sfText_setCharacterSize(new_text, 75);
        sfText_setScale(new_text, (sfVector2f){0.1, 0.1});
        sfText_setString(new_text, my_strndup(str, 48));
        sfText_setPosition(new_text, (sfVector2f){pos.x, pos.y + i * 10});
        sfText_setColor(new_text, color);
        sfRenderWindow_drawText(rpg->glib->window->window, new_text, NULL);
        sfText_destroy(new_text);
        str += 48;
    }
}
