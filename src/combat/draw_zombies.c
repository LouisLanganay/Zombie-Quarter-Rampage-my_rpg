/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_zombies
*/

#include "rpg.h"

void draw_zombies(zombies_t *list, rpg_t *rpg)
{
    zombies_t *tmp = list;
    if (tmp == NULL) return;
    while (tmp != NULL) {
        if (tmp->direction == 1) {
            sfSprite_setScale(tmp->sprite, (sfVector2f){-2, 2});
            sfSprite_setPosition(tmp->sprite, (sfVector2f){tmp->pos.x,
            tmp->pos.y});
        } else {
            sfSprite_setScale(tmp->sprite, (sfVector2f){2, 2});
            sfp(tmp->sprite, (sfVector2f){tmp->pos.x - 152, tmp->pos.y});
        }
        sfRenderWindow_drawSprite(windoww, tmp->sprite, NULL);
        if (tmp->hp > 0) {
            sfRectangleShape_setSize(tmp->hp_bar, (sfVector2f){tmp->hp, 10});
            sfRectangleShape_setPosition(tmp->hp_bar,
            (sfVector2f){tmp->pos.x - 72 - tmp->hp / 2, tmp->pos.y + 20});
            sfRenderWindow_drawRectangleShape(windoww, tmp->hp_bar, NULL);
        }
        tmp = tmp->next;
    }
}
