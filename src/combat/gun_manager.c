/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** gun_manager
*/

#include "rpg.h"

float shot_angle(sfVector2f pos, sfVector2i mouse)
{
    float angle = atan2(mouse.y - pos.y, mouse.x - pos.x) * 180 / M_PI;
    return angle;
}

void use_gun(rpg_t *rpg, sfClock *clock_shoot, bullets_t **bullets)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfClock_getElapsedTime(clock_shoot).microseconds / 200000.0 > 1) {
        insert_bullet(bullets, rpg);
        sfClock_restart(clock_shoot);
    }
}

void gun_manager(rpg_t *rpg, combat_t *combat)
{
    use_gun(rpg, combat->clock_shoot, &combat->bullets);
    move_bullets(combat->bullets, rpg);
    draw_bullets(combat->bullets, rpg);
    delete_bullet_outmap(&combat->bullets);
}
