/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_game_win_screen
*/

#include "rpg.h"

static void init_game_win_screen_bg(player_t *player, rpg_t *rpg)
{
    player->game_win->background = sfRectangleShape_create();
    sfRectangleShape_setSize(player->game_win->background,
        (sfVector2f){1920, 1080});
    sfRectangleShape_setFillColor(player->game_win->background,
        (sfColor){0, 0, 0, 0});
    sfRectangleShape_setOrigin(player->game_win->background,
        (sfVector2f){960, 540});
}

void init_game_win_screen(player_t *player, rpg_t *rpg)
{
    player->game_win = malloc(sizeof(game_lost_t));
    player->game_win->clock = sfClock_create();
    player->game_win->text_clock = sfClock_create();
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = WIN_TEXT;
    my_text->pos = (sfVector2f){0, 0};
    my_text->font = gl_get_font(rpg->glib, TLOU_FONT);
    my_text->scale = (sfVector2f){0.5, 0.5};
    my_text->color = (sfColor){255, 255, 255, 255};
    my_text->string = "You survive";
    my_text->size = 50;
    gl_create_text(rpg->glib, my_text);
    sfFloatRect rect = sfText_getGlobalBounds(gl_get_text(rpg->glib,
        WIN_TEXT));
    sfText_setOrigin(gl_get_text(rpg->glib, WIN_TEXT),
        (sfVector2f){rect.width, rect.height / 2});
    init_game_win_screen_bg(player, rpg);
}
