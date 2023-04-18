/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_keybinds_keys
*/

#include "rpg.h"

static void init_keybinds_keys_up(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = SETTINGS_KEY_UP;
    my_text->pos = (sfVector2f){1500, 550};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "Move Forward";
    my_text->size = 250;
    gl_create_text(rpg->glib, my_text);
}

static void init_keybinds_keys_down(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = SETTINGS_KEY_DOWN;
    my_text->pos = (sfVector2f){1500, 550 + 1 * 45};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "Move Backward";
    my_text->size = 250;
    gl_create_text(rpg->glib, my_text);
}

static void init_keybinds_keys_left(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = SETTINGS_KEY_LEFT;
    my_text->pos = (sfVector2f){1500, 550 + 2 * 45};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "Move Left";
    my_text->size = 250;
    gl_create_text(rpg->glib, my_text);
}

static void init_keybinds_keys_right(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = SETTINGS_KEY_RIGHT;
    my_text->pos = (sfVector2f){1500, 550 + 3 * 45};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "Move Right";
    my_text->size = 250;
    gl_create_text(rpg->glib, my_text);
}

void init_keybinds_keys(rpg_t *rpg)
{
    init_keybinds_keys_up(rpg);
    init_keybinds_keys_down(rpg);
    init_keybinds_keys_left(rpg);
    init_keybinds_keys_right(rpg);
    init_keybinds_otherkeys(rpg);
}
