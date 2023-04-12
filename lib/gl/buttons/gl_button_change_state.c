/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_button_change_state
*/

#include "../gl.h"

static void gl_button_change_state_change_rect(buttons_t *tmp)
{
    if (tmp->disabled == sfTrue) {
        tmp->rect.left = tmp->rect.width * 2;
        return;
    }
    if (tmp->hovered == sfTrue) {
        tmp->rect.left = tmp->rect.width;
        return;
    }
    tmp->rect.left = 0;
}

void gl_button_change_state(int id, buttons_t *buttons, sfBool state)
{
    buttons_t *tmp = buttons;
    while (tmp != NULL) {
        if (tmp->id == id) {
            tmp->disabled = state;
            tmp->rect.left = tmp->rect.width * 2;
            gl_button_change_state_change_rect(tmp);
            return;
        }
        tmp = tmp->next;
    }
    write(2, "(gl_button_change_state) Button id not found\n", 45);
}
