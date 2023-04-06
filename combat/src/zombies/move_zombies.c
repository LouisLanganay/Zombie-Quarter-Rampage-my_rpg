/*
** EPITECH PROJECT, 2023
** combat
** File description:
** move_zombies
*/

#include "../../combat/includes/rpg.h"

int check_range_attack(zombies_t *tmp, rpg_t *rpg, sfClock *attack_speed, int distance_player)
{
    if (distance_player <= 30 || (distance_player == 31 && tmp->last_distance == 30)) {
        tmp = tmp->next;
        if (sfTime_asSeconds(sfClock_getElapsedTime(attack_speed)) > 1) {
            sfClock_restart(attack_speed);
            rpg->player->hp -= tmp->damage;
            if (rpg->player->hp <= 0)
                exit(0);
        }
        return (1);
    }
    return (0);
}

void move_zombie_x(zombies_t *tmp, rpg_t *rpg, int distance_player)
{
    if (tmp->pos.x > rpg->player->pos.x) {
        tmp->pos.x -= tmp->speed;
        sfRectangleShape_move(tmp->hitbox, (sfVector2f){-tmp->speed, 0});
        sfSprite_setScale(tmp->sprite, (sfVector2f){-2, 2});
        if (tmp->direction != 1) {
            tmp->direction = 1;
        }
    }
    else {
        tmp->pos.x += tmp->speed;
        sfRectangleShape_move(tmp->hitbox, (sfVector2f){tmp->speed, 0});
        sfSprite_setScale(tmp->sprite, (sfVector2f){2, 2});
        if (tmp->direction != 0) {
            tmp->direction = 0;
        }
    }
}

void move_zombie_y(zombies_t *tmp, rpg_t *rpg, int distance_player)
{
    if (distance_player < 600)
        if (tmp->pos.y > rpg->player->pos.y) {
            tmp->pos.y -= tmp->speed;
            sfRectangleShape_move(tmp->hitbox, (sfVector2f){0, -tmp->speed});
        }
        else {
            tmp->pos.y += tmp->speed;
            sfRectangleShape_move(tmp->hitbox, (sfVector2f){0, tmp->speed});
        }
}

void move_zombies(zombies_t *list, rpg_t *rpg, sfClock *attack_speed)
{
    zombies_t *tmp = list;
    if (tmp == NULL)
        return;
    int distance_player = 0;
    sfVector2f pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 2));
    while (tmp != NULL) {
        distance_player = distance(pos, tmp->pos);
        if (distance_player <= 30 || (distance_player == 31 && tmp->last_distance == 30)) {
            tmp = tmp->next;
            if (sfTime_asSeconds(sfClock_getElapsedTime(attack_speed)) > 1) {
                sfClock_restart(attack_speed);
                rpg->player->hp -= tmp->damage;
                if (rpg->player->hp <= 0)
                    exit(0);
            }
            continue;
        }
        if (tmp->pos.x > pos.x) {
            tmp->pos.x -= tmp->speed;
            sfRectangleShape_move(tmp->hitbox, (sfVector2f){-tmp->speed, 0});
            sfSprite_setScale(tmp->sprite, (sfVector2f){-2, 2});
            if (tmp->direction != 1) {
                tmp->direction = 1;
            }

        }
        else {
            tmp->pos.x += tmp->speed;
            sfRectangleShape_move(tmp->hitbox, (sfVector2f){tmp->speed, 0});
            sfSprite_setScale(tmp->sprite, (sfVector2f){2, 2});
            if (tmp->direction != 0) {
                tmp->direction = 0;
            }
        }
        if (distance_player < 600)
            if (tmp->pos.y > pos.y) {
                tmp->pos.y -= tmp->speed;
                sfRectangleShape_move(tmp->hitbox, (sfVector2f){0, -tmp->speed});
            }
            else {
                tmp->pos.y += tmp->speed;
                sfRectangleShape_move(tmp->hitbox, (sfVector2f){0, tmp->speed});
            }
        tmp->last_distance = distance_player;
        tmp = tmp->next;
    }
}
