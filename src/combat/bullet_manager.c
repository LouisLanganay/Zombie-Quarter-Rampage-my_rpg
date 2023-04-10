/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** bullet_manager
*/

#include "rpg.h"

void insert_bullet(bullets_t **list, rpg_t *rpg)
{
    bullets_t *new_node = malloc(sizeof(bullets_t));
    new_node->speed = 10;
    new_node->pos = sfSprite_getPosition(rpg->glib->sprites->next->sprite);
    new_node->pos.x += -110;
    new_node->pos.y += 50;
    new_node->sprite = sfSprite_create();
    new_node->texture = sfTexture_createFromFile(bullet, NULL);
    new_node->rect = (sfIntRect){0, 0, 100, 100};
    new_node->scale = (sfVector2f){1.0, 1.0};
    new_node->angle = shot_angle(new_node->pos,
    sfMouse_getPositionRenderWindow(rpg->glib->window->window));
    new_node->status = 0;
    new_node->next = *list;
    sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
    sfSprite_setTextureRect(new_node->sprite, new_node->rect);
    sfSprite_setScale(new_node->sprite, new_node->scale);
    sfSprite_setPosition(new_node->sprite, new_node->pos);
    *list = new_node;
}

void draw_bullets(bullets_t *bullets, rpg_t *rpg)
{
    bullets_t *tmp = bullets;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(windoww, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void move_bullets(bullets_t *bullets, rpg_t *rpg)
{
    bullets_t *tmp = bullets;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        tmp->pos.x += cos(tmp->angle * M_PI / 180) * tmp->speed;
        tmp->pos.y += sin(tmp->angle * M_PI / 180) * tmp->speed;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        tmp = tmp->next;
    }
}

void delete_bullet_status(bullets_t **list)
{
    bullets_t *tmp = *list;
    bullets_t *prev = NULL;

    while (tmp != NULL && tmp->status == 1) {
        *list = tmp->next;
        free(tmp);
        tmp = *list;
    }
    while (tmp != NULL) {
        while (tmp != NULL && tmp->status == 0) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp == NULL)
            return;
        prev->next = tmp->next;
        free(tmp);
        tmp = prev->next;
    }
}

void delete_bullet_outmap(bullets_t **list)
{
    bullets_t *tmp = *list;
    bullets_t *prev = NULL;

    while (tmp != NULL && tmp->pos.x > 1920) {
        *list = tmp->next;
        free(tmp);
        tmp = *list;
    }
    while (tmp != NULL) {
        while (tmp != NULL && tmp->pos.x < 1920) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp == NULL)
            return;
        prev->next = tmp->next;
        free(tmp);
        tmp = prev->next;
    }
}
