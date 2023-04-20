/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** gun_manager
*/

#include "rpg.h"

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
