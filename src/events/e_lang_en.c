/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** e_lang_en.c
*/
#include "rpg.h"

void e_langue_en(int id, void *main)
{
    (void)id;
    rpg_t *rpg = (rpg_t *)main;
    rpg->settings->game_language = EN;
}
