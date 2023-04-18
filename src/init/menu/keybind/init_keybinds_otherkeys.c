/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_keybinds_keys
*/

#include "rpg.h"

static void init_keybinds_keys_inv(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = SETTINGS_KEY_INV;
    my_text->pos = (sfVector2f){1500, 550 + 4 * 45};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "Inventory";
    my_text->size = 250;
    gl_create_text(rpg->glib, my_text);
}

void init_keybinds_otherkeys(rpg_t *rpg)
{
    init_keybinds_keys_inv(rpg);
}
