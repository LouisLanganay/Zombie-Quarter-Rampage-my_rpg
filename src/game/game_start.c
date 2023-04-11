/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** game_start
*/

#include "rpg.h"

void game_start(rpg_t *rpg)
{
    if (rpg->maps_loaded == 0) {
        gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
        draw_splash_screen(rpg);
    } else {
        start_sound(rpg, MAIN_THEME_ID);
        draw_menu(rpg);
    }
}
