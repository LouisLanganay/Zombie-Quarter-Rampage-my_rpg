/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** move_player
*/

#include "../../includes/rpg.h"

void move_player(rpg_t *rpg, sfClock *clock)
{
    float time = sfClock_getElapsedTime(clock).microseconds;
    float seconds = time / 1000000.0;
    sfVector2f sprite_pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 2));
    if (seconds > 0.0075) {
        if (sfKeyboard_isKeyPressed(sfKeyZ) && sprite_pos.y > 200)
            sfSprite_move(gl_get_sprite(rpg->glib, 2), (sfVector2f){0, -5});
        if (sfKeyboard_isKeyPressed(sfKeyS) && sprite_pos.y < 620)
            sfSprite_move(gl_get_sprite(rpg->glib, 2), (sfVector2f){0, 5});
        if (sfKeyboard_isKeyPressed(sfKeyQ) && sprite_pos.x > 10)
            sfSprite_move(gl_get_sprite(rpg->glib, 2), (sfVector2f){-5, 0});
        if (sfKeyboard_isKeyPressed(sfKeyD) && sprite_pos.x < 1850)
            sfSprite_move(gl_get_sprite(rpg->glib, 2), (sfVector2f){5, 0});
        sfClock_restart(clock);
    }
}
