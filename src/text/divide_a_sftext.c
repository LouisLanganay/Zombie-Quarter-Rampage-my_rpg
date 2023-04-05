/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** divide_a_sftext
*/

#include "rpg.h"

void divide_a_sftext(sfText *text, sfVector2f pos, rpg_t *rpg)
{
    const char *str = sfText_getString(text);
    int len = my_strlen(str);
    int nb_text = len / 52 + 1;
    sfText *new_text = NULL;


    for (int i = 0; i < nb_text; i++) {
        new_text = sfText_copy(text);
        sfText_setString(new_text, my_strndup(str, 52));
        sfText_setPosition(new_text, (sfVector2f){pos.x, pos.y + i * 10});
        sfRenderWindow_drawText(rpg->glib->window->window, new_text, NULL);
        str += 52;
    }
}
