/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_ddown_draw_childs
*/

#include "../gl.h"

static sfBool gl_ddown_is_hovered(dropdown_t *ddown, GLib_t *glib)
{
    sfVector2i posM = sfMouse_getPositionRenderWindow(glib->window->window);
    sfVector2f posB = sfRectangleShape_getPosition(ddown->background);
    sfVector2f size = sfRectangleShape_getSize(ddown->background);
    if (posM.x >= posB.x && posM.x <= posB.x + size.x &&
    posM.y >= posB.y && posM.y <= posB.y + size.y) {
        return sfTrue;
    }
    return sfFalse;
}

static void gl_draw_ddown_id(dropdown_t *ddown, GLib_t *glib, void *main)
{
    if (gl_ddown_is_hovered(ddown, glib) == sfTrue) {
        sfRectangleShape_setFillColor(
            ddown->background, ddown->bg_colors.hovered);
        if (ddown->call_action != NULL && sfMouse_isButtonPressed(sfMouseLeft))
            ddown->call_action(ddown->id, main);
    } else {
        sfRectangleShape_setFillColor(ddown->background,
            ddown->bg_colors.normal);
    }
    sfRectangleShape_setPosition(ddown->background, (sfVector2f){
        ddown->pos.x - 10, ddown->pos.y
    });
    sfRenderWindow_drawRectangleShape(glib->window->window,
        ddown->background, NULL);
    if (ddown->text_id)
        gl_draw_text(glib, ddown->text_id);
}

void gl_ddown_draw_childs(dropdown_t *tmp, GLib_t *glib, void *main)
{
    dropdown_t *child = tmp->childs;
    while (child != NULL) {
        gl_draw_ddown_id(child, glib, main);
        child = child->next;
    }
}
