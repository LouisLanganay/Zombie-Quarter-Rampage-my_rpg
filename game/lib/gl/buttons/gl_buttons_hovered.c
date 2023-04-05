/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_buttons_hovered
*/

#include "../gl.h"

static sfBool gl_button_is_hovered(buttons_t *button, sfVector2i posM)
{
    sfVector2f posB = sfSprite_getPosition(button->sprite);
    if (posM.x >= posB.x && posM.x <= posB.x + button->rect.width &&
    posM.y >= posB.y && posM.y <= posB.y + button->rect.height) {
        return sfTrue;
    }
    return sfFalse;
}

static void gl_button_hovered(buttons_t *tmp, void *main)
{
    if (tmp->hovered != sfTrue) {
        tmp->hovered = sfTrue;
        if (tmp->ss_hover != NULL) {
            sfSound_play(tmp->ss_hover);
        }
    }
    tmp->rect.left = tmp->rect.width;
    if (tmp->call_action != NULL && sfMouse_isButtonPressed(sfMouseLeft)) {
        if (tmp->ss_click != NULL) {
            sfSound_play(tmp->ss_click);
        }
        tmp->rect.left = tmp->rect.width * 3;
        tmp->call_action(tmp->id, main);
    }
}

static void gl_button_not_hovered(buttons_t *tmp)
{
    tmp->hovered = sfFalse;
    tmp->rect.left = 0;
}

void gl_buttons_hovered(buttons_t *buttons, window_t *window, void *main)
{
    buttons_t *tmp = buttons;
    sfVector2i posM = sfMouse_getPositionRenderWindow(window->window);
    while (tmp != NULL) {
        if (tmp->disabled == sfTrue) {
            tmp = tmp->next;
            continue;
        }
        sfVector2f posB = sfSprite_getPosition(tmp->sprite);
        if (gl_button_is_hovered(tmp, posM) == sfTrue)
            gl_button_hovered(tmp, main);
        else
            gl_button_not_hovered(tmp);
        tmp = tmp->next;
    }
}
