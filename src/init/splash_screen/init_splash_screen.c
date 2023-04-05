/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_splash_screen
*/

#include "rpg.h"

static void init_splash_screen_text2(rpg_t *rpg)
{
    sfVector2f screen_center = (sfVector2f){rpg->glib->window->mode.width / 2,
        rpg->glib->window->mode.height / 2};
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = SPLASH_SCREEN_TEXT2;
    my_text->pos = (sfVector2f){screen_center.x, 500};
    my_text->font = gl_get_font(rpg->glib, TLOU_FONT);
    my_text->scale = (sfVector2f){0.5, 0.5};
    my_text->color = (sfColor){255, 255, 255, 255};
    my_text->string = "RAMPAGE";
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
    sfFloatRect rect = sfText_getGlobalBounds(gl_get_text(rpg->glib,
        SPLASH_SCREEN_TEXT2));
    sfText_setOrigin(gl_get_text(rpg->glib, SPLASH_SCREEN_TEXT2),
        (sfVector2f){rect.width, rect.height / 2});
}

static void init_splash_screen_text1(rpg_t *rpg)
{
    sfVector2f screen_center = (sfVector2f){rpg->glib->window->mode.width / 2,
        rpg->glib->window->mode.height / 2};
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = SPLASH_SCREEN_TEXT1;
    my_text->pos = (sfVector2f){screen_center.x, 300};
    my_text->font = gl_get_font(rpg->glib, TLOU_FONT);
    my_text->scale = (sfVector2f){0.5, 0.5};
    my_text->color = (sfColor){255, 255, 255, 255};
    my_text->string = "ZOMBIE QUARTER";
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
    sfFloatRect rect = sfText_getGlobalBounds(gl_get_text(rpg->glib,
        SPLASH_SCREEN_TEXT1));
    sfText_setOrigin(gl_get_text(rpg->glib, SPLASH_SCREEN_TEXT1),
        (sfVector2f){rect.width, rect.height / 2});
}

void init_splash_screen(rpg_t *rpg)
{
    rpg->splash_screen = malloc(sizeof(splash_screen_t));
    rpg->splash_screen->clock = sfClock_create();
    init_splash_screen_text1(rpg);
    init_splash_screen_text2(rpg);
}
