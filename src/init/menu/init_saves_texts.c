/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_saves_texts
*/

#include "rpg.h"

static void init_saves_texts_one(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = TXT_SAVE1;
    my_text->pos = (sfVector2f){rpg->glib->window->mode.width / 2.65,
    rpg->glib->window->mode.height / 8 + 30};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "Save 1";
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
}

static void init_saves_texts_two(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = TXT_SAVE2;
    my_text->pos = (sfVector2f){rpg->glib->window->mode.width / 2.65,
    rpg->glib->window->mode.height / 3.5 + 30};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "Save 2";
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
}

static void init_saves_texts_three(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = TXT_SAVE3;
    my_text->pos = (sfVector2f){rpg->glib->window->mode.width / 2.65,
    rpg->glib->window->mode.height / 2.2 + 30};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "Save 3";
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
}

void init_saves_texts(rpg_t *rpg)
{
    init_saves_texts_one(rpg);
    init_saves_texts_two(rpg);
    init_saves_texts_three(rpg);
}
