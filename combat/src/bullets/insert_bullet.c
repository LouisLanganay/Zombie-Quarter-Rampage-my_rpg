/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** insert_bullet
*/

#include "../../includes/rpg.h"

void insert_bullet(bullets_t **list, rpg_t *rpg)
{
    bullets_t *new_node = malloc(sizeof(bullets_t));
    new_node->speed = 10;
    new_node->pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 2));
    new_node->sprite = sfSprite_create();
    new_node->texture = sfTexture_createFromFile("assets/bullet.png", NULL);
    new_node->rect = (sfIntRect){0, 0, 100, 100};
    new_node->scale = (sfVector2f){1.0, 1.0};
    new_node->angle = shot_angle(new_node->pos, sfMouse_getPositionRenderWindow(rpg->glib->window->window));
    new_node->status = 0;
    new_node->next = *list;
    sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
    sfSprite_setTextureRect(new_node->sprite, new_node->rect);
    sfSprite_setScale(new_node->sprite, new_node->scale);
    sfSprite_setPosition(new_node->sprite, new_node->pos);
    *list = new_node;
}