/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_player_moovment
*/

#include "rpg.h"

static int check_player_moovment_complex(
    player_t *player,
    map_t *map,
    rpg_t *rpg
)
{
    if (player->keys->down.state == 1 && player->keys->right.state == 1) {
        if (RIGHT_CONDITION) player->pos.x += 1 * PLAYER_SPEED;
        if (DOWN_CONDITION) player->pos.y += 1 * PLAYER_SPEED;
        return 1;
    }
    if (player->keys->down.state == 1 && player->keys->left.state == 1) {
        if (LEFT_CONDITION) player->pos.x -= 1 * PLAYER_SPEED;
        if (DOWN_CONDITION) player->pos.y += 1 * PLAYER_SPEED;
        return 1;
    }
    return 0;
}

static int check_player_moovment_complex_bis(
    player_t *player,
    map_t *map,
    rpg_t *rpg
)
{
    if (player->keys->up.state == 1 && player->keys->right.state == 1) {
        if (RIGHT_CONDITION) player->pos.x += 1 * PLAYER_SPEED;
        if (UP_CONDITION) player->pos.y -= 1 * PLAYER_SPEED;
        return 1;
    }
    if (player->keys->up.state == 1 && player->keys->left.state == 1) {
        if (LEFT_CONDITION) player->pos.x -= 1 * PLAYER_SPEED;
        if (UP_CONDITION) player->pos.y -= 1 * PLAYER_SPEED;
        return 1;
    }
    return 0;
}

void check_player_moovment(player_t *player, map_t *map, rpg_t *rpg)
{
    if (player->in_dialogue == 1) return;
    check_interactions(player, map, rpg);
    if (check_player_moovment_complex(player, map, rpg) == 1) return;
    if (check_player_moovment_complex_bis(player, map, rpg) == 1) return;

    if (player->keys->up.state == 1)
        if (UP_CONDITION) player->pos.y -= 1 * PLAYER_SPEED;
    if (player->keys->down.state == 1)
        if (DOWN_CONDITION) player->pos.y += 1 * PLAYER_SPEED;
    if (player->keys->left.state == 1)
        if (LEFT_CONDITION) player->pos.x -= 1 * PLAYER_SPEED;
    if (player->keys->right.state == 1)
        if (RIGHT_CONDITION) player->pos.x += 1 * PLAYER_SPEED;
}
