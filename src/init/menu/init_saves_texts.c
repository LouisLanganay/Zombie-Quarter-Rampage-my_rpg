/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_saves_texts
*/

#include "rpg.h"

static void init_saves_texts_one(rpg_t *rpg, bool_t played)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = TXT_SAVE1;
    my_text->pos = (sfVector2f){rpg->glib->window->mode.width / 2.65,
    rpg->glib->window->mode.height / 8 + 30};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = (played == b_true ? "Save 1" : "Empty");
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
}

static void init_saves_texts_two(rpg_t *rpg, bool_t played)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = TXT_SAVE2;
    my_text->pos = (sfVector2f){rpg->glib->window->mode.width / 2.65,
    rpg->glib->window->mode.height / 3.5 + 30};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = (played == b_true ? "Save 2" : "Empty");
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
}

static void init_saves_texts_three(rpg_t *rpg, bool_t played)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = TXT_SAVE3;
    my_text->pos = (sfVector2f){rpg->glib->window->mode.width / 2.65,
    rpg->glib->window->mode.height / 2.2 + 30};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = (played == b_true ? "Save 3" : "Empty");
    my_text->size = 300;
    gl_create_text(rpg->glib, my_text);
}

void init_saves_texts(rpg_t *rpg)
{
    parsed_data_t *d1 = jp_parse("saves/save1.json");
    parsed_data_t *d2 = jp_parse("saves/save2.json");
    parsed_data_t *d3 = jp_parse("saves/save3.json");
    init_saves_texts_one(rpg, jp_search(d1, "save_file.played")->value.p_bool);
    init_saves_texts_two(rpg, jp_search(d2, "save_file.played")->value.p_bool);
    init_saves_texts_three(rpg,
        jp_search(d3, "save_file.played")->value.p_bool);
}
