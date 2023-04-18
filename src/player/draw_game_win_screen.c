/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_game_win_screen
*/

#include "rpg.h"

static void draw_game_win_screen_bg_text(rpg_t *rpg)
{
    int alpha = sfText_getColor(gl_get_text(rpg->glib, WIN_TEXT)).a;
    sfText_setColor(gl_get_text(rpg->glib, WIN_TEXT),
        (sfColor){255, 255, 255, alpha + 1});
}

static void draw_game_win_screen_bg_bg(rpg_t *rpg)
{
    int alpha = sfRectangleShape_getFillColor(
        rpg->player->game_win->background).a;
    sfRectangleShape_setFillColor(rpg->player->game_win->background,
        (sfColor){0, 0, 0, alpha + 1});
}

static void draw_game_win_screen_bg(rpg_t *rpg)
{
    sfVector2f vpos = sfView_getCenter(sfRenderWindow_getView(RGWW));
    sfVector2f vsize = sfView_getSize(sfRenderWindow_getView(RGWW));
    sfVector2f pos = (sfVector2f){vpos.x - vsize.x / 2, vpos.y - vsize.y / 2};
    time_t time = sfClock_getElapsedTime(rpg->player->game_win->text_clock)
        .microseconds;
    float seconds = time / 1000000.0;

    if (seconds > 0.025) {
        draw_game_win_screen_bg_text(rpg);
        draw_game_win_screen_bg_bg(rpg);
        sfClock_restart(rpg->player->game_win->text_clock);
    }
    sfText_setPosition(gl_get_text(rpg->glib, WIN_TEXT), vpos);
    sfRectangleShape_setPosition(rpg->player->game_win->background, vpos);
    sfRenderWindow_drawRectangleShape(RGWW,
        rpg->player->game_win->background, NULL);
    gl_draw_text(rpg->glib, WIN_TEXT);
}

void draw_game_win_screen(rpg_t *rpg)
{
    if (rpg->game_state != GAME_WIN) return;

    time_t time = sfClock_getElapsedTime(rpg->player->game_win->clock)
        .microseconds;
    float seconds = time / 1000000.0;

    draw_game_win_screen_bg(rpg);

    if (seconds > 5) {
        rpg->game_state = MENU;
        sfRenderWindow_setView(RGWW, sfRenderWindow_getDefaultView(RGWW));
        sfClock_restart(rpg->player->game_win->clock);
        reset_a_save(rpg);
    }
}
