/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_add_child_ddown
*/

#include "../gl.h"

static void gl_add_child_in_linked_list(dropdown_t *tmp, dropdown_t *child)
{
    child->next = tmp->childs;
    tmp->childs = child;
}

void gl_add_child_ddown(dropdown_t *ddowns, int id, dropdown_t *child)
{
    dropdown_t *tmp = ddowns;

    while (tmp) {
        if (tmp->id == id) {
            gl_add_child_in_linked_list(tmp, child);
            return;
        }
        tmp = tmp->next;
    }
    write(2, "(gl_add_child_ddown) Ddown id doesn't exist\n", 45);
}
