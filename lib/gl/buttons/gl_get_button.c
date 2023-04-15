/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_get_button
*/

#include "../gl.h"

buttons_t *gl_get_button(buttons_t *buttons, int id)
{
    buttons_t *tmp = buttons;

    while (tmp) {
        if (tmp->id == id)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}
