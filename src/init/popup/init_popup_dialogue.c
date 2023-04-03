/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_popup_dialogue
*/

#include "rpg.h"

static void init_popup_dialogue_choice_one(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = PLAYER_DIALOGUE_CHOICE_ONE_TEXT;
    my_text->pos = (sfVector2f){0, 0};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = (sfColor){255, 255, 255, 255};
    my_text->string = "";
    my_text->size = 75;
    gl_create_text(rpg->glib, my_text);
}

static void init_popup_dialogue_choice_two(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = PLAYER_DIALOGUE_CHOICE_TWO_TEXT;
    my_text->pos = (sfVector2f){0, 0};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = (sfColor){255, 255, 255, 255};
    my_text->string = "";
    my_text->size = 75;
    gl_create_text(rpg->glib, my_text);
}

static void init_popup_dialogue_text(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = PLAYER_DIALOGUE_TEXT;
    my_text->pos = (sfVector2f){0, 0};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = (sfColor){255, 255, 255, 255};
    my_text->string = "";
    my_text->size = 75;
    gl_create_text(rpg->glib, my_text);
}

void init_popup_dialogue(rpg_t *rpg)
{
    init_popup_dialogue_text(rpg);
    init_popup_dialogue_choice_one(rpg);
    init_popup_dialogue_choice_two(rpg);
}
