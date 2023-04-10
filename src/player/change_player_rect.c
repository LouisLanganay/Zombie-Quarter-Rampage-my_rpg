/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** change_player_rect
*/

#include "rpg.h"

static int player_in_moovment(player_t *player)
{
    if (player->keys->up.state == 1)
        return (1);
    if (player->keys->down.state == 1)
        return (1);
    if (player->keys->left.state == 1)
        return (1);
    if (player->keys->right.state == 1)
        return (1);
    return (0);

}

static void change_player_rect_annimate(player_t *player)
{
    time_t time = sfClock_getElapsedTime(player->assets->clock).microseconds;
    float seconds = time / 1000000.0;
    if (seconds > (player_in_moovment(player) ? 0.1 : 0.25)) {
        player->rect.top += PLAYER_SPRITE_HEIGHT;
        if (player->rect.top >= PLAYER_SPRITE_HEIGHT * 6)
            player->rect.top = 0;
        sfClock_restart(player->assets->clock);
    }
}

static void change_player_rect_idle(player_t *player)
{
    if (sfKeyboard_isKeyPressed(player->keys->interact.key) == sfTrue) {
        player->rect.left = player->rect.width * 8;
        return;
    }
    if (player->keys->last_direction == DOWN)
        player->rect.left = player->rect.width * 4;
    if (player->keys->last_direction == UP)
        player->rect.left = player->rect.width * 5;
    if (player->keys->last_direction == RIGHT)
        player->rect.left = player->rect.width * 6;
    if (player->keys->last_direction == LEFT)
        player->rect.left = player->rect.width * 7;
}

void change_player_rect(player_t *player)
{
    change_player_rect_idle(player);
    if (player->in_dialogue != 0) return;
    if (player->keys->up.state == 1) {
        player->keys->last_direction = UP;
        player->rect.left = player->rect.width * 1;
    }
    if (player->keys->down.state == 1) {
        player->keys->last_direction = DOWN;
        player->rect.left = 0;
    }
    if (player->keys->left.state == 1) {
        player->keys->last_direction = LEFT;
        player->rect.left = player->rect.width * 3;
    }
    if (player->keys->right.state == 1) {
        player->keys->last_direction = RIGHT;
        player->rect.left = player->rect.width * 2;
    }
    change_player_rect_annimate(player);
    sfSprite_setTextureRect(player->sprite, player->rect);
}
