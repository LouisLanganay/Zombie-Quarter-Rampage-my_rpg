/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_menu_keys
*/

#include "rpg.h"

static void draw_menu_keys_up(rpg_t *rpg)
{
    int id_up = get_key_id(RPK->up.key, rpg);
    gl_draw_text(rpg->glib, SETTINGS_KEY_UP);
    if (id_up < 0) return;
    sfSprite_setPosition(RPA->key_sprite[id_up], (sfVector2f) {1465, 560});
    sfSprite_setScale(RPA->key_sprite[id_up], (sfVector2f){3, 3});
    sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id_up], NULL);
    sfSprite_setScale(RPA->key_sprite[id_up], (sfVector2f){1, 1});
}

static void draw_menu_keys_down(rpg_t *rpg)
{
    int id_down = get_key_id(RPK->down.key, rpg);
    gl_draw_text(rpg->glib, SETTINGS_KEY_DOWN);
    if (id_down < 0) return;
    sfSprite_setPosition(RPA->key_sprite[id_down], (sfVector2f){1465, 605});
    sfSprite_setScale(RPA->key_sprite[id_down], (sfVector2f){3, 3});
    sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id_down], NULL);
    sfSprite_setScale(RPA->key_sprite[id_down], (sfVector2f){1, 1});
}

static void draw_menu_keys_left(rpg_t *rpg)
{
    int id_left = get_key_id(RPK->left.key, rpg);
    gl_draw_text(rpg->glib, SETTINGS_KEY_LEFT);
    if (id_left < 0) return;
    sfSprite_setPosition(RPA->key_sprite[id_left], (sfVector2f){1465, 650});
    sfSprite_setScale(RPA->key_sprite[id_left], (sfVector2f){3, 3});
    sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id_left], NULL);
    sfSprite_setScale(RPA->key_sprite[id_left], (sfVector2f){1, 1});
}

static void draw_menu_keys_right(rpg_t *rpg)
{
    int id_right = get_key_id(RPK->right.key, rpg);
    gl_draw_text(rpg->glib, SETTINGS_KEY_RIGHT);
    if (id_right < 0) return;
    sfSprite_setPosition(RPA->key_sprite[id_right], (sfVector2f){1465, 695});
    sfSprite_setScale(RPA->key_sprite[id_right], (sfVector2f){3, 3});
    sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id_right], NULL);
    sfSprite_setScale(RPA->key_sprite[id_right], (sfVector2f){1, 1});
}

void draw_menu_keys(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(RGW->window, RM->settings_bg_key_sprite, NULL);
    draw_menu_keys_up(rpg);
    draw_menu_keys_down(rpg);
    draw_menu_keys_left(rpg);
    draw_menu_keys_right(rpg);
}
