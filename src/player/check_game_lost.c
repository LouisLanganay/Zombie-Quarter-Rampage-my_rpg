/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_game_lost
*/

#include "rpg.h"

void check_game_lost(rpg_t *rpg)
{
    if (rpg->player->hp > 20)
        if (sfSound_getStatus(
                gl_get_sound(rpg->glib, HEART_SOUND_ID)->sound) == sfPlaying)
            fade_sound(rpg, HEART_SOUND_ID, 10);
    if (rpg->player->hp <= 20)
        start_sound(rpg, HEART_SOUND_ID);
    if (rpg->player->hp <= 0 && rpg->game_state != GAME_LOST) {
        rpg->game_state = GAME_LOST;
        sfClock_restart(rpg->player->game_lost->clock);
    }
}
