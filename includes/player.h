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

    #define PLAYER_SPRITE_PATH "resources/assets/player/player.png"

    #define PLAYER_DA_PATH "resources/assets/player/down_attack.png"
    #define PLAYER_DI_PATH "resources/assets/player/down_idle.png"
    #define PLAYER_DW_PATH "resources/assets/player/down_walk.png"
    #define PLAYER_UA_PATH "resources/assets/player/up_attack.png"
    #define PLAYER_UI_PATH "resources/assets/player/up_idle.png"
    #define PLAYER_UW_PATH "resources/assets/player/up_walk.png"
    #define PLAYER_SA_PATH "resources/assets/player/side_attack.png"
    #define PLAYER_SI_PATH "resources/assets/player/side_idle.png"
    #define PLAYER_SW_PATH "resources/assets/player/side_walk.png"

    #define PLAYER_KEYBOARD_PATH "resources/assets/keys/keyboard.png"
    #define PLAYER_KEYBOARD_PATH2 "resources/assets/keys/extras.png"
    #define PLAYER_INVENTORY_PATH "ressources/assets/items/items_packs.png"
    #define PLAYER_GUI_PATH "resources/assets/gui/UI.png"

    #define PLAYER_INTERACT_TEXT 613255
    #define PLAYER_SPRITE_WIDTH 16
    #define PLAYER_SPRITE_HEIGHT 35
    #define PLAYER_SPEED 60

    #define PLAYER_DIALOGUE_TEXT 613256
    #define PLAYER_DCHOICE_ONE_TEXT 613257
    #define PLAYER_DCHOICE_TWO_TEXT 613258
    #define PLAYER_DIALOGUE_TEXT_ESCAPE 613259

    #define EVENT_KEY_PRESSED 5465
    #define EVENT_KEY_RELEASED 5466

    #define UP_CONDITION ((check_colisions(map, (sfVector2f){player->pos.x +   \
    player->rect.width / 2, player->pos.y - 7}, player, rpg) == 0))

    #define DOWN_CONDITION ((check_colisions(map, (sfVector2f){player->pos.x \
    + player->rect.width / 2, player->pos.y + 5}, player, rpg) == 0))

    #define LEFT_CONDITION (check_colisions(map, (sfVector2f){player->pos.x, \
    player->pos.y}, player, rpg) == 0)

    #define RIGHT_CONDITION (check_colisions(map, (sfVector2f){player->pos.x + \
    player->rect.width, player->pos.y}, player, rpg) == 0)


    typedef struct p_key_s {
        int state;
        sfKeyCode key;
    } p_key_t;

    typedef enum p_direction_e {
        UP,
        DOWN,
        LEFT,
        RIGHT
    } p_direction_t;

    typedef struct keys_s {
        p_direction_t last_direction;
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
        sfClock *clock;
        sfTexture **key_texture;
        sfSprite **key_sprite;
        sfTexture **items_texture;
        sfSprite **key_choice1;
        sfSprite **key_choice2;
        sfSprite *dialog_box;
        sfTexture *down_attack;
        sfTexture *down_idle;
        sfTexture *down_walk;
        sfTexture *up_attack;
        sfTexture *up_idle;
        sfTexture *up_walk;
        sfTexture *side_attack;
        sfTexture *side_idle;
        sfTexture *side_walk;
    } player_assets_t;

    typedef struct player_s {
        int hp;
        int in_dialogue;
        sfRectangleShape *hitbox;
        sfVector2f pos;
        sfView *view;
        sfClock *clock;
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        keys_t *keys;
        player_assets_t *assets;
    } player_t;

#endif
