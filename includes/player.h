/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** player
*/

#ifndef _PLAYER_H__
    #define _PLAYER_H__

    #include "rpg.h"

    #define SPAWN_X 111 * 16
    #define SPAWN_Y 43 * 16

    #define SPAWN_INTO_HOUSE_X 20 * 16
    #define SPAWN_INTO_HOUSE_Y 17 * 16
    #define SPAWN_OUT_HOUSE_X 111 * 16
    #define SPAWN_OUT_HOUSE_Y 40 * 16

    #define PLAYER_SPRITE_PATH "resources/player/player_sprite.png"
    #define PLAYER_KEYBOARD_PATH "resources/assets/keys/keyboard.png"
    #define PLAYER_KEYBOARD_PATH2 "resources/assets/keys/extras.png"
    #define PLAYER_INTERACT_TEXT 613255
    #define PLAYER_SPRITE_WIDTH 25
    #define PLAYER_SPRITE_HEIGHT 45
    #define PLAYER_SPEED 1.5

    #define PLAYER_DIALOGUE_TEXT 613256
    #define PLAYER_DIALOGUE_CHOICE_ONE_TEXT 613257
    #define PLAYER_DIALOGUE_CHOICE_TWO_TEXT 613258
    #define PLAYER_DIALOGUE_TEXT_ESCAPE 613259

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


    typedef struct p_key_s {
        int state;
        sfKeyCode key;
    } p_key_t;

    typedef struct keys_s {
        p_key_t up;
        p_key_t down;
        p_key_t left;
        p_key_t right;
        p_key_t interact;
        p_key_t choice_one;
        p_key_t choice_two;
        p_key_t escape;
    } keys_t;

    typedef struct player_assets_s {
        sfTexture **key_texture;
        sfSprite **key_sprite;
        sfSprite **key_choice1;
        sfSprite **key_choice2;
    } player_assets_t;

    typedef struct player_s {
        int hp;
        int in_dialogue;
        sfRectangleShape *hitbox;
        sfVector2f pos;
        sfView *view;
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        keys_t *keys;
        player_assets_t *assets;
    } player_t;

#endif
