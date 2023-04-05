/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_key_id
*/

#include "rpg.h"

static void draw_interaction_popup_change_size(
    int id,
    keyboard_images_t *keyboard,
    rpg_t *rpg)
{
    if (id != -1) {
        if (sfKeyboard_isKeyPressed(keyboard[id].key) == sfTrue) {
            sfSprite_setScale(RPA->key_sprite[id], (sfVector2f){0.9, 0.9});
        } else {
            sfSprite_setScale(RPA->key_sprite[id], (sfVector2f){1, 1});
        }
    }
}

int get_key_id(sfKeyCode key, rpg_t *rpg)
{
    int id = -1;
    keyboard_images_t *keyboard = get_keyboard_array();

    for (long unsigned int x = 0; keyboard[x].key != sfKeyUnknown; x++) {
        if (keyboard[x].key == key) {
            id = keyboard[x].id;
            break;
        }
    }
    draw_interaction_popup_change_size(id, keyboard, rpg);
    free(keyboard);
    return id;
}
