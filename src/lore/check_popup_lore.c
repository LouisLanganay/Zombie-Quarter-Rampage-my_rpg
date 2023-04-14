/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_popup_lore
*/

#include "rpg.h"

void check_popup_lore(rpg_t *rpg)
{
    if (rpg->player->lore_open == 1) {
        if (sfKeyboard_isKeyPressed(rpg->player->keys->escape.key) == sfTrue) {
            rpg->player->lore_open = 0;
            rpg->player->lore_sound_played = 0;
        }
    }
}
