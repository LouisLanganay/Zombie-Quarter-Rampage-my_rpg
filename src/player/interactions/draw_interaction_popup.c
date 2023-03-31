/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_interaction_popup
*/

#include "rpg.h"

void draw_interaction_popup(
    rpg_t *rpg,
    sfVector2f pos,
    sfKeyCode key,
    char *str)
{
    int id = -1;
    keyboard_images_t *keyboard = get_keyboard_array();

    for (long unsigned int x = 0; keyboard[x].key != sfKeyUnknown; x++) {
        if (keyboard[x].key == key) {
            id = keyboard[x].id;
            break;
        }
    }
    if (str != NULL)
        sfText_setString(gl_get_text(rpg->glib, PLAYER_INTERACT_TEXT),
            my_strcat_malloc("Press      to ", str));
    sfText_setPosition(gl_get_text(rpg->glib, PLAYER_INTERACT_TEXT),
        (sfVector2f) {pos.x + 50, pos.y - 30});
    gl_draw_text(rpg->glib, PLAYER_INTERACT_TEXT);
    if (id != -1) {
        sfSprite_setPosition(rpg->player->assets->key_sprite[id],
            (sfVector2f) {pos.x + 70, pos.y - 33});
        sfRenderWindow_drawSprite(rpg->glib->window->window,
            rpg->player->assets->key_sprite[id], NULL);
    }

    free(keyboard);
}
