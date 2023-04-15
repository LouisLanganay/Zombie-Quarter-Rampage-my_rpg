/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** gun_manager
*/

#include "rpg.h"

    // change_player_rect_idle(player);
    // if (player->in_dialogue != 0) return;
    // if (player->keys->up.state == 1) {
    //     player->keys->last_direction = UP;
    //     player->rect.left = player->rect.width * 1;
    // }
    // if (player->keys->down.state == 1) {
    //     player->keys->last_direction = DOWN;
    //     player->rect.left = 0;
    // }
    // if (player->keys->left.state == 1) {
    //     player->keys->last_direction = LEFT;
    //     player->rect.left = player->rect.width * 3;
    // }
    // if (player->keys->right.state == 1) {
    //     player->keys->last_direction = RIGHT;
    //     player->rect.left = player->rect.width * 2;
    // }
    // change_player_rect_annimate(player);
    // sfSprite_setTextureRect(player->sprite, player->rect);
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

void change_direction_player_shoot_angle(rpg_t *rpg,
sfVector2i mouse, sfVector2f pos)
{
    float angle = atan2(mouse.y - pos.y, mouse.x - pos.x) * 180 / M_PI;

    if (angle > -100 && angle < 100) {
        rpg->player->rect.left = rpg->player->rect.width * 2;
        rpg->player->keys->last_direction = RIGHT;
    }
    if (angle < -150 || angle > 150) {
        rpg->player->rect.left = 0;
        rpg->player->keys->last_direction = LEFT;
    }
    if (angle > 100 && angle < 150) {
        rpg->player->rect.left = rpg->player->rect.width * 3;
        rpg->player->keys->last_direction = DOWN;
    }
    if (angle > -150 && angle < -100) {
        rpg->player->rect.left = rpg->player->rect.width * 1;
        rpg->player->keys->last_direction = UP;
    }
}

static void use_gun(rpg_t *rpg, sfClock *clock_shoot, bullets_t **bullets)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfClock_getElapsedTime(clock_shoot).microseconds / 200000.0 > 1) {
        sfClock_restart(clock_shoot);
        insert_bullet(bullets, rpg);
        change_direction_player_shoot_angle(rpg,
        sfMouse_getPositionRenderWindow(rpg->glib->window->window),
        rpg->glib->sprites->next->pos);
        sfRenderWindow_drawSprite(rpg->glib->window->window,
        rpg->player->sprite, NULL);
    }
}

void gun_manager(rpg_t *rpg, combat_t *combat)
{
    use_gun(rpg, combat->clock_shoot, &combat->bullets);
    move_bullets(combat->bullets, rpg);
    draw_bullets(combat->bullets, rpg);
    delete_bullet_outmap(&combat->bullets);
}
