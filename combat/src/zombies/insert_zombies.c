/*
** EPITECH PROJECT, 2023
** combat
** File description:
** insert_zombies
*/

#include "../../combat/includes/rpg.h"

static int random_type(void)
{
    int nb = rand() % 100;
    if (nb < 90)
        return (1);
    if (nb >= 90)
        return (2);
    return (1);
}

void insert_zombies(rpg_t *rpg, zombies_t **list)
{
    zombies_t *new_node = malloc(sizeof(zombies_t));
    new_node->pos = (sfVector2f){1920 + rand() % 500, 620 - rand() % 420};
    new_node->type = random_type();
    new_node->hp = 100;
    new_node->damage = 10;
    new_node->speed = 1;
    new_node->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(new_node->hitbox, new_node->pos);
    sfRectangleShape_setSize(new_node->hitbox, (sfVector2f){60, 110});
    sfRectangleShape_setFillColor(new_node->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(new_node->hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(new_node->hitbox, 3);
    sfRectangleShape_setScale(new_node->hitbox, (sfVector2f){-1, 1});
    sfRectangleShape_move(new_node->hitbox, (sfVector2f){-48, 40});
    new_node->sprite = sfSprite_create();
    new_node->rect = (sfIntRect){0, 0, 72, 72};
    new_node->scale = (sfVector2f){-2.0, 2.0};
    new_node->alive = 0;
    new_node->animation = 0;
    new_node->direction = 3;
    new_node->last_distance = 0;
    //sfSprite_setTextureRect(new_node->sprite, new_node->rect);
    sfSprite_setPosition(new_node->sprite, new_node->pos);
    sfSprite_setScale(new_node->sprite, new_node->scale);

    if (new_node->type == 1) {
        new_node->texture = sfTexture_createFromFile("assets/zombie_0.png", NULL);
        sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
        new_node->next = *list;
        *list = new_node;
        return;
    }
    if (new_node->type == 2) {
        new_node->texture = sfTexture_createFromFile("assets/witch0.png", NULL);
        new_node->hp = 50;
        new_node->damage = 20;
        new_node->speed = 3;
        sfRectangleShape_move(new_node->hitbox, (sfVector2f){0, -40});
    }
    //if (new_node->type == 3) {
    //    new_node->texture = sfTexture_createFromFile("assets/fat0.png", NULL);
    //    new_node->hp = 200;
    //    new_node->damage = 50;
    //    new_node->speed = 0.5;
    //}
    sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
    new_node->next = *list;
    *list = new_node;
}
