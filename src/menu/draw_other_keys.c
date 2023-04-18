/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_other_keys
*/

#include "rpg.h"

static void draw_menu_keys_inv(rpg_t *rpg)
{
    int id_up = get_key_id(RPK->inventory.key, rpg);
    gl_draw_text(rpg->glib, SETTINGS_KEY_INV);
    if (id_up < 0) return;
    sfSprite_setPosition(RPA->key_sprite[id_up], (sfVector2f){1465, 695 + 45*1});
    sfSprite_setScale(RPA->key_sprite[id_up], (sfVector2f){3, 3});
    sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id_up], NULL);
    sfSprite_setScale(RPA->key_sprite[id_up], (sfVector2f){1, 1});
}

void draw_other_keys(rpg_t *rpg)
{
    draw_menu_keys_inv(rpg);
}
