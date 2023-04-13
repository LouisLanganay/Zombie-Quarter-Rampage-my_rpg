/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_hud
*/

#include "rpg.h"

static void init_hud_hp(rpg_t *rpg)
{
    rpg->hud->hp_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->hud->hp_bar, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(rpg->hud->hp_bar,
        (sfColor){236, 110, 110, 255});
    rpg->hud->hp_bar_back = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->hud->hp_bar_back, (sfVector2f){102, 6});
    sfRectangleShape_setOrigin(rpg->hud->hp_bar_back, (sfVector2f){1, 1});
    sfRectangleShape_setFillColor(rpg->hud->hp_bar_back,
        (sfColor){27, 27, 27, 100});
}

static void init_hud_hunger(rpg_t *rpg)
{
    rpg->hud->hunger_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->hud->hunger_bar, (sfVector2f){0, 0});
    sfRectangleShape_setFillColor(rpg->hud->hunger_bar,
        (sfColor){236, 167, 84, 255});
    rpg->hud->hunger_bar_back = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->hud->hunger_bar_back, (sfVector2f){102, 6});
    sfRectangleShape_setOrigin(rpg->hud->hunger_bar_back, (sfVector2f){1, 1});
    sfRectangleShape_setFillColor(rpg->hud->hunger_bar_back,
        (sfColor){27, 27, 27, 100});
}

void init_hud(rpg_t *rpg)
{
    rpg->hud = malloc(sizeof(hud_t));
    init_hud_hp(rpg);
    init_hud_hunger(rpg);
}
