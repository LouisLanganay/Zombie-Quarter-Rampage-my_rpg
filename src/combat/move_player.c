/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** move_player
*/

#include "rpg.h"

static void up_move(rpg_t *rpg, float s)
{
    rpg->player->pos.y -= 500 * s;
    sfSprite_move(rpg->glib->sprites->next->sprite,
    (sfVector2f){0, -500 * s});
}

static void down_move(rpg_t *rpg, float s)
{
    rpg->player->pos.y += 500 * s;
    sfSprite_move(rpg->glib->sprites->next->sprite,
    (sfVector2f){0, 500 * s});
}

static void left_move(rpg_t *rpg, float s)
{
    rpg->player->pos.x -= 500 * s;
    sfSprite_move(rpg->glib->sprites->next->sprite,
    (sfVector2f){-500 * s, 0});
}

static void right_move(rpg_t *rpg, float s)
{
    rpg->player->pos.x += 500 * s;
    sfSprite_move(rpg->glib->sprites->next->sprite,
    (sfVector2f){500 * s, 0});
}

void move_player(rpg_t *rpg, sfClock *clock)
{
    float time = sfClock_getElapsedTime(clock).microseconds;
    float s = time / 1000000.0;
    sfVector2f pos = sfSprite_getPosition(rpg->glib->sprites->next->sprite);
    if (sfKeyboard_isKeyPressed(sfKeyZ) && pos.y > 200.0)
        up_move(rpg, s);
    if (sfKeyboard_isKeyPressed(sfKeyS) && pos.y < 600.0)
        down_move(rpg, s);
    if (sfKeyboard_isKeyPressed(sfKeyQ) && pos.x > 170.0)
        left_move(rpg, s);
    if (sfKeyboard_isKeyPressed(sfKeyD) && pos.x < 1980.0)
        right_move(rpg, s);
    sfClock_restart(clock);
}
