/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_settings
*/

#include "rpg.h"

void init_settings(rpg_t *rpg)
{
    rpg->settings = malloc(sizeof(settings_t));
    rpg->settings->game_language = FR;
    rpg->settings->volume = 100;
}
