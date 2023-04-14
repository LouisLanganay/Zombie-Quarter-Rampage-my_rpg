/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_background.c
*/

#include "rpg.h"

void init_background(rpg_t *rpg)
{
    sfImage *image = sfImage_createFromFile
    ("resources/assets/background/background_1.jpg");
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    rpg->background->active = false;
    rpg->background->background_menu_s = sfSprite_create();

    sfSprite_setTexture(rpg->background->background_menu_s, texture, sfTrue);
}
