/*
** EPITECH PROJECT, 2023
** combat
** File description:
** draw_zombies
*/

#include "../../combat/includes/rpg.h"

void draw_zombies(zombies_t *list, rpg_t *rpg)
{
    zombies_t *tmp = list;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(rpg->glib->window->window, tmp->sprite, NULL);
        sfRenderWindow_drawRectangleShape(rpg->glib->window->window, tmp->hitbox, NULL);
        tmp = tmp->next;
    }
}
