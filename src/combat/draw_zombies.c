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
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        if (tmp->direction == 1) {
            sfSprite_setScale(tmp->sprite, (sfVector2f){-2, 2});
            sfSprite_setPosition(tmp->sprite, (sfVector2f){tmp->pos.x,
            tmp->pos.y});
        } else {
            sfSprite_setScale(tmp->sprite, (sfVector2f){2, 2});
            sfSprite_setPosition(tmp->sprite, (sfVector2f){tmp->pos.x - 152,
            tmp->pos.y});
        }
        sfRenderWindow_drawSprite(rpg->glib->window->window,
        tmp->sprite, NULL);
        sfRenderWindow_drawRectangleShape(rpg->glib->window->window,
        tmp->hitbox, NULL);
        tmp = tmp->next;
    }
}
