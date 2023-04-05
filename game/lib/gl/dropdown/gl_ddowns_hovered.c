/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_ddowns_hovered
*/

#include "../gl.h"

static sfBool gl_ddown_check_if_child_hovered(
    dropdown_t *ddown,
    sfVector2i posM
)
{
    dropdown_t *tmp = ddown->childs;
    sfVector2f posB;
    sfVector2f size;
    while (tmp != NULL) {
        posB = sfRectangleShape_getPosition(tmp->background);
        size = sfRectangleShape_getSize(tmp->background);
        if (posM.x >= posB.x && posM.x <= posB.x + size.x &&
        posM.y >= posB.y && posM.y <= posB.y + size.y) {
            return sfTrue;
        }
        tmp = tmp->next;
    }
    return sfFalse;
}

static sfBool gl_ddown_is_hovered(dropdown_t *ddown, sfVector2i posM)
{
    sfVector2f posB = sfRectangleShape_getPosition(ddown->background);
    sfVector2f size = sfRectangleShape_getSize(ddown->background);
    if (posM.x >= posB.x && posM.x <= posB.x + size.x &&
    posM.y >= posB.y && posM.y <= posB.y + size.y ||
    (gl_ddown_check_if_child_hovered(ddown, posM) == sfTrue &&
    ddown->hovered == sfTrue)) {
        return sfTrue;
    }
    return sfFalse;
}

static void gl_ddown_hovered(dropdown_t *tmp, void *main, GLib_t *glib)
{
    sfVector2f size = sfRectangleShape_getSize(tmp->background);
    sfVector2f posB = sfRectangleShape_getPosition(tmp->background);
    sfVector2i posM = sfMouse_getPositionRenderWindow(glib->window->window);
    sfRectangleShape_setFillColor(tmp->background, tmp->bg_colors.hovered);
    gl_ddown_draw_childs(tmp, glib, main);
    if (tmp->hovered != sfTrue) {
        tmp->hovered = sfTrue;
    }
    if (tmp->call_action != NULL && sfMouse_isButtonPressed(sfMouseLeft)) {
        if (posM.x >= posB.x && posM.x <= posB.x + size.x &&
        posM.y >= posB.y && posM.y <= posB.y + size.y)
            tmp->call_action(tmp->id, main);
    }
}

static void gl_ddowns_not_hovered(dropdown_t *tmp, GLib_t *glib, void *main)
{
    sfRectangleShape_setFillColor(tmp->background, tmp->bg_colors.normal);
    tmp->hovered = sfFalse;
}

void gl_ddowns_hovered(GLib_t *glib, window_t *window, void *main)
{
    dropdown_t *tmp = glib->ddowns;
    sfVector2i posM = sfMouse_getPositionRenderWindow(window->window);
    while (tmp != NULL) {
        if (tmp->disabled == sfTrue) {
            tmp = tmp->next;
            continue;
        }
        if (gl_ddown_is_hovered(tmp, posM) == sfTrue)
            gl_ddown_hovered(tmp, main, glib);
        else
            gl_ddowns_not_hovered(tmp, glib, main);
        tmp = tmp->next;
    }
}
