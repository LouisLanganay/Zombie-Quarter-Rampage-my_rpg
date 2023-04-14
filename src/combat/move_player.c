/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** move_player
*/

#include "rpg.h"

void move_player(rpg_t *rpg, sfClock *clock)
{
    float time = sfClock_getElapsedTime(clock).microseconds;
    float seconds = time / 1000000.0;
    sfVector2f pos = sfSprite_getPosition(rpg->glib->sprites->next->sprite);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && pos.y > 200.0) {
        rpg->player->pos.y -= 500 * seconds;
        sfSprite_move(rpg->glib->sprites->next->sprite,
        (sfVector2f){0, -500 * seconds});
    }
    if (sfKeyboard_isKeyPressed(sfKeyS) && pos.y < 600.0) {
        rpg->player->pos.y += 500 * seconds;
        sfSprite_move(rpg->glib->sprites->next->sprite,
        (sfVector2f){0, 500 * seconds});
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && pos.x > 170.0) {
        rpg->player->pos.x -= 500 * seconds;
        sfSprite_move(rpg->glib->sprites->next->sprite,
        (sfVector2f){-500 * seconds, 0});
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && pos.x < 1980.0) {
        rpg->player->pos.x += 500 * seconds;
        sfSprite_move(rpg->glib->sprites->next->sprite,
        (sfVector2f){500 * seconds, 0});
    }
    sfClock_restart(clock);
}
