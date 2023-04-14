/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** move_zombies
*/

#include "rpg.h"

static int distance(sfVector2f pos1, sfVector2f pos2)
{
    return (sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2)));
}

static int attack_player(rpg_t *rpg, sfClock *attack_clock,
float atk_speed, int dmg)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(attack_clock)) > atk_speed) {
        sfClock_restart(attack_clock);
        rpg->player->hp -= dmg;
        if (rpg->player->hp <= 0)
            exit(0);
    }
}

static void move_y_zombie(int distance_player, zombies_t *tmp, sfVector2f pos)
{
    if (distance_player < 600)
        if (tmp->pos.y > pos.y) {
            tmp->pos.y -= tmp->speed;
            sfRectangleShape_move(tmp->hitbox, (sfVector2f){0, -tmp->speed});
        } else {
            tmp->pos.y += tmp->speed;
            sfRectangleShape_move(tmp->hitbox, (sfVector2f){0, tmp->speed});
        }
}

static void move_x_zombie(int distance_player, zombies_t *tmp, sfVector2f pos)
{
    if (tmp->pos.x > pos.x) {
        tmp->pos.x -= tmp->speed;
        sfRectangleShape_move(tmp->hitbox, (sfVector2f){-tmp->speed, 0});
        sfSprite_setScale(tmp->sprite, (sfVector2f){-2, 2});
        if (tmp->direction != 1) {
            tmp->direction = 1;
        }
    } else {
        tmp->pos.x += tmp->speed;
        sfRectangleShape_move(tmp->hitbox, (sfVector2f){tmp->speed, 0});
        sfSprite_setScale(tmp->sprite, (sfVector2f){2, 2});
        if (tmp->direction != 0) {
            tmp->direction = 0;
        }
    }
}

void move_zombies(zombies_t *list, rpg_t *rpg)
{
    zombies_t *tmp = list;
    int distance_player = 0;
    sfVector2f pos = sfSprite_getPosition(rpg->glib->sprites->next->sprite);
    while (tmp != NULL) {
        (tmp->status_anim == 2) ? (tmp = tmp->next) : (0);
        (tmp == NULL) ? ({return;}) : 0;
        distance_player = distance(pos, tmp->pos);
        if (distance_player <= 30 || (distance_player == 31 &&
        tmp->last_distance == 30)) {
            swap_status_anim_cbt(tmp);
            attack_player(rpg,tmp->attack_clock,tmp->attack_speed,tmp->damage);
            tmp = tmp->next;
            continue;
        }
        swap_status_anim_move(tmp);
        move_x_zombie(distance_player, tmp, pos);
        move_y_zombie(distance_player, tmp, pos);
        tmp->last_distance = distance_player;
        tmp = tmp->next;
    }
}
