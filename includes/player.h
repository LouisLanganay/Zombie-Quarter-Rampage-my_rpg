/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** player
*/

#ifndef _PLAYER_H__
    #define _PLAYER_H__

    #include "rpg.h"

    #define SPAWN_X 1500
    #define SPAWN_Y 300

    #define SPAWN_INTO_HOUSE_X 20 * 16
    #define SPAWN_INTO_HOUSE_Y 17 * 16
    #define SPAWN_OUT_HOUSE_X 111 * 16
    #define SPAWN_OUT_HOUSE_Y 40 * 16

    #define PLAYER_SPRITE_PATH "resources/player/player_sprite.png"
    #define PLAYER_SPRITE_WIDTH 25
    #define PLAYER_SPRITE_HEIGHT 45
    #define PLAYER_SPEED 1.5

    #define EVENT_KEY_PRESSED 5465
    #define EVENT_KEY_RELEASED 5466

    #define UP_CONDITION ((check_colisions(map, (sfVector2f){player->pos.x +   \
    player->rect.width / 2, player->pos.y - 3}, player, rpg) == 0))

    #define DOWN_CONDITION ((check_colisions(map, (sfVector2f){player->pos.x \
    + player->rect.width / 2, player->pos.y + 3}, player, rpg) == 0))

    #define LEFT_CONDITION (check_colisions(map, (sfVector2f){player->pos.x, \
    player->pos.y}, player, rpg) == 0)

    #define RIGHT_CONDITION (check_colisions(map, (sfVector2f){player->pos.x + \
    player->rect.width, player->pos.y}, player, rpg) == 0)


    typedef struct moovement_key_s {
        int state;
        sfKeyCode key;
    } moovement_key_t;

    typedef struct keys_s {
        moovement_key_t up;
        moovement_key_t down;
        moovement_key_t left;
        moovement_key_t right;
        moovement_key_t interact;
    } keys_t;

    typedef struct player_s {
        sfRectangleShape *hitbox;
        sfVector2f pos;
        sfView *view;
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        keys_t *keys;
    } player_t;

#endif
