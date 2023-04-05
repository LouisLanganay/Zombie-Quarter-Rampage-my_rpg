/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_button_change_state
*/

#include "../gl.h"

void gl_button_change_state(int id, buttons_t *buttons, sfBool state)
{
    buttons_t *tmp = buttons;
    while (tmp != NULL) {
        if (tmp->id == id) {
            tmp->disabled = state;
            tmp->rect.left = tmp->rect.width * 2;
            return;
        }
        tmp = tmp->next;
    }
    write(2, "(gl_button_change_state) Button id not found\n", 45);
}
