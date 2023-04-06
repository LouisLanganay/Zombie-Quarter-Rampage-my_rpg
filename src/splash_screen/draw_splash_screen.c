/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_splash_screen
*/

#include "rpg.h"

void draw_splash_screen(rpg_t *rpg)
{
    gl_draw_text(rpg->glib, SPLASH_SCREEN_TEXT1);
    gl_draw_text(rpg->glib, SPLASH_SCREEN_TEXT2);
}
