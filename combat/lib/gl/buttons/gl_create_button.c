/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_button
*/

#include "../gl.h"

static int gl_create_button_check_id(buttons_t *buttons, int id)
{
    buttons_t *tmp = buttons;
    while (tmp != NULL) {
        if (tmp->id == id)
            return write(2, "(gl_create_button) Button id already exist\n", 43);
        tmp = tmp->next;
    }
    return (0);
}

static void gl_create_button_set_sounds(buttons_t *tmp, buttons_t *button)
{
    if (tmp->sb_hover != NULL) {
        tmp->sb_hover = button->sb_hover;
        tmp->ss_hover = sfSound_create();
        sfSound_setBuffer(tmp->ss_hover, tmp->sb_hover);
    } else {
        tmp->ss_hover = NULL;
        tmp->sb_hover = NULL;
    }
    if (tmp->sb_click != NULL) {
        tmp->sb_click = button->sb_click;
        tmp->ss_click = sfSound_create();
        sfSound_setBuffer(tmp->ss_click, tmp->sb_click);
    } else {
        tmp->ss_click = NULL;
        tmp->sb_click = NULL;
    }
}

static int handle_error(buttons_t *button)
{
    if (button->id < 1)
        return write(2,
            "(gl_create_button) Button id can't be negative or 0\n", 52);
    if (button->pos.x < 0 || button->pos.y < 0)
        return write(2,
            "(gl_create_button) Button position can't be negative\n", 54);
    if (button->rect.width < 0 || button->rect.height < 0)
        return write(2,
            "(gl_create_button) Button rect can't be negative\n", 49);
    if (button->sprite == NULL)
        return write(2,
            "(gl_create_button) Button sprite can't be NULL\n", 47);
    if (button->texture == NULL)
        return write(2,
            "(gl_create_button) Button texture can't be NULL\n", 48);
    return (0);
}

static void gl_create_button_set_textures(buttons_t *tmp, buttons_t *button)
{
    tmp->sprite = button->sprite;
    tmp->texture = button->texture;
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    sfSprite_setTextureRect(tmp->sprite, tmp->rect);
    sfSprite_setPosition(tmp->sprite, tmp->pos);
}

int gl_create_button(GLib_t *glib, buttons_t *button)
{
    if (gl_create_button_check_id(glib->buttons, button->id) != 0)
        return (84);
    if (handle_error(button) != 0)
        return (84);
    buttons_t *tmp = malloc(sizeof(*tmp));
    tmp->id = button->id;
    tmp->pos = button->pos;
    tmp->rect = button->rect;
    tmp->call_action = button->call_action;
    tmp->hovered = sfFalse;
    tmp->disabled = sfFalse;
    tmp->sb_hover = button->sb_hover;
    tmp->sb_click = button->sb_click;
    gl_create_button_set_sounds(tmp, button);
    gl_create_button_set_textures(tmp, button);
    tmp->next = glib->buttons;
    glib->buttons = tmp;
    free(button);
    return (0);
}
