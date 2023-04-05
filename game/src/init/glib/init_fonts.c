/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_fonts
*/

#include "rpg.h"


void init_fonts(rpg_t *rpg)
{
    rpg->glib->fonts = NULL;
    gl_create_font(rpg->glib, MINECRAFT_FONT, "resources/fonts/Minecraft.ttf");
}
