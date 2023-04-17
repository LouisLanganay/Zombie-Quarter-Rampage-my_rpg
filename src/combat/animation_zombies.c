/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** animation_zombies
*/

#include "rpg.h"

static void animation_zombie1_atk(zombies_t *l)
{
    if (l->animation == 7)
        l->animation = 0;
    if (l->animation == 0)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_ATK0, NULL), sfTrue);
    if (l->animation == 1)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_ATK1, NULL), sfTrue);
    if (l->animation == 2)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_ATK2, NULL), sfTrue);
    if (l->animation == 3)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_ATK3, NULL), sfTrue);
    if (l->animation == 4)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_ATK4, NULL), sfTrue);
    if (l->animation == 5)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_ATK5, NULL), sfTrue);
    if (l->animation == 6)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_ATK6, NULL), sfTrue);
}

static void animation_zombie1_move(zombies_t *l)
{
    if (l->animation == 8) {
        l->animation = 0;
    }
    if (l->animation == 0)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_0, NULL), sfTrue);
    if (l->animation == 1)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_1, NULL), sfTrue);
    if (l->animation == 2)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_2, NULL), sfTrue);
    if (l->animation == 3)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_3, NULL), sfTrue);
    if (l->animation == 4)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_4, NULL), sfTrue);
    if (l->animation == 5)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_5, NULL), sfTrue);
    if (l->animation == 6)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_6, NULL), sfTrue);
    if (l->animation == 7)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_7, NULL), sfTrue);

}

static void animation_zombie1_death(zombies_t *l)
{
    if (l->animation == 7)
        l->alive = 1;
    if (l->animation == 0)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_DEATH0, NULL), sfTrue);
    if (l->animation == 1)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_DEATH1, NULL), sfTrue);
    if (l->animation == 2)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_DEATH2, NULL), sfTrue);
    if (l->animation == 3)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_DEATH3, NULL), sfTrue);
    if (l->animation == 4)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_DEATH4, NULL), sfTrue);
    if (l->animation == 5)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_DEATH5, NULL), sfTrue);
    if (l->animation == 6)
        sfSprite_setTexture(l->sprite, sfc(ZOMBIE_DEATH6, NULL), sfTrue);
}

static void animation_zombie1(zombies_t *l)
{
    if (l->status_anim == 0)
        animation_zombie1_move(l);
    if (l->status_anim == 1)
        animation_zombie1_atk(l);
    if (l->status_anim == 2)
        animation_zombie1_death(l);
}

void animation_zombie(zombies_t *l)
{
    zombies_t *tmp = l;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        if (sfs(sfClock_getElapsedTime(tmp->clock_animation)) > 0.15) {
            tmp->animation++;
            animation_zombie1(tmp);
            sfClock_restart(tmp->clock_animation);
        }

        tmp = tmp->next;
    }
}
