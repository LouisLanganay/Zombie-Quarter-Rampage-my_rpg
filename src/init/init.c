/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init
*/

#include "rpg.h"

void init(rpg_t *rpg)
{
    init_glib(rpg);
    init_language(rpg);
    init_settings(rpg);
    init_player(rpg);
    init_popup_interaction(rpg);
    init_popup_dialogue(rpg);
    init_save(rpg);
    init_splash_screen(rpg);
}
