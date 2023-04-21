/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** animation_zombies2
*/

#include "rpg.h"

static void animation_witch1_atk(zombies_t *l)
{
    if (l->animation == 7)
        l->animation = 0;
    if (l->animation == 0)
        sfSprite_setTexture(l->sprite, sfc(WITCH_ATK0, NULL), sfTrue);
    if (l->animation == 1)
        sfSprite_setTexture(l->sprite, sfc(WITCH_ATK1, NULL), sfTrue);
    if (l->animation == 2)
        sfSprite_setTexture(l->sprite, sfc(WITCH_ATK2, NULL), sfTrue);
    if (l->animation == 3)
        sfSprite_setTexture(l->sprite, sfc(WITCH_ATK3, NULL), sfTrue);
    if (l->animation == 4)
        sfSprite_setTexture(l->sprite, sfc(WITCH_ATK4, NULL), sfTrue);
    if (l->animation == 5)
        sfSprite_setTexture(l->sprite, sfc(WITCH_ATK5, NULL), sfTrue);
    if (l->animation == 6)
        sfSprite_setTexture(l->sprite, sfc(WITCH_ATK6, NULL), sfTrue);
}

static void animation_witch1_move(zombies_t *l)
{
    if (l->animation == 8) {
        l->animation = 0;
    }
    if (l->animation == 0)
        sfSprite_setTexture(l->sprite, sfc(WITCH_0, NULL), sfTrue);
    if (l->animation == 1)
        sfSprite_setTexture(l->sprite, sfc(WITCH_1, NULL), sfTrue);
    if (l->animation == 2)
        sfSprite_setTexture(l->sprite, sfc(WITCH_2, NULL), sfTrue);
    if (l->animation == 3)
        sfSprite_setTexture(l->sprite, sfc(WITCH_3, NULL), sfTrue);
    if (l->animation == 4)
        sfSprite_setTexture(l->sprite, sfc(WITCH_4, NULL), sfTrue);
    if (l->animation == 5)
        sfSprite_setTexture(l->sprite, sfc(WITCH_5, NULL), sfTrue);
    if (l->animation == 6)
        sfSprite_setTexture(l->sprite, sfc(WITCH_6, NULL), sfTrue);
    if (l->animation == 7)
        sfSprite_setTexture(l->sprite, sfc(WITCH_7, NULL), sfTrue);
}

static void animation_witch1_death(zombies_t *l)
{
    if (l->animation == 7)
        l->alive = 1;
    if (l->animation == 0)
        sfSprite_setTexture(l->sprite, sfc(WITCH_DEATH0, NULL), sfTrue);
    if (l->animation == 1)
        sfSprite_setTexture(l->sprite, sfc(WITCH_DEATH1, NULL), sfTrue);
    if (l->animation == 2)
        sfSprite_setTexture(l->sprite, sfc(WITCH_DEATH2, NULL), sfTrue);
    if (l->animation == 3)
        sfSprite_setTexture(l->sprite, sfc(WITCH_DEATH3, NULL), sfTrue);
    if (l->animation == 4)
        sfSprite_setTexture(l->sprite, sfc(WITCH_DEATH4, NULL), sfTrue);
    if (l->animation == 5)
        sfSprite_setTexture(l->sprite, sfc(WITCH_DEATH5, NULL), sfTrue);
    if (l->animation == 6)
        sfSprite_setTexture(l->sprite, sfc(WITCH_DEATH6, NULL), sfTrue);
}

void animation_witch1(zombies_t *l)
{
    if (l->status_anim == 0)
        animation_witch1_move(l);
    if (l->status_anim == 1)
        animation_witch1_atk(l);
    if (l->status_anim == 2)
        animation_witch1_death(l);
}
