/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_interaction_popup
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

static int get_key_id(sfKeyCode key, rpg_t *rpg)
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

void draw_interaction_popup(
    rpg_t *rpg,
    sfVector2f pos,
    sfKeyCode key,
    char *str)
{
    int id = get_key_id(key, rpg);

    if (str != NULL)
        sfText_setString(gl_get_text(rpg->glib, PLAYER_INTERACT_TEXT),
        my_strcat_malloc(get_language(rpg, "interact_press__to", RSG), str));

    sfText_setPosition(gl_get_text(rpg->glib, PLAYER_INTERACT_TEXT),
        (sfVector2f) {pos.x + 55, pos.y - 30});
    gl_draw_text(rpg->glib, PLAYER_INTERACT_TEXT);

    if (id != -1) {
        if (RSG == EN)
            sfSprite_setPosition(RPA->key_sprite[id],
                (sfVector2f) {pos.x + 85, pos.y - 25});
        if (RSG == FR)
            sfSprite_setPosition(RPA->key_sprite[id],
                (sfVector2f) {pos.x + 109, pos.y - 25});
        sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id], NULL);
    }
}
