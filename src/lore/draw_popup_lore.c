/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_popup_lore
*/

#include "rpg.h"

static void draw_popup_lore_play_sound(rpg_t *rpg)
{
    if (rpg->player->lore_sound_played == 0) {
        rpg->player->lore_sound_played = 1;
        gl_play_sound(rpg->glib, PAPER_SOUND_ID);
    }
}

void draw_popup_lore(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(rpg->player->view->view);
    devide_text_t *devide = NULL;
    if (rpg->player->lore_open != 1) return;
    draw_popup_lore_play_sound(rpg);
    sfSprite_setPosition(RPA->lore_box, (sfVector2f){view_pos.x, view_pos.y});
    sfRenderWindow_drawSprite(rpg->glib->window->window, RPA->lore_box, NULL);
    draw_interaction_popup(rpg,(sfVector2f){view_pos.x - 105, view_pos.y + 140},
        RPK->escape.key, get_language(rpg, "close_paper", RSG));

    devide = malloc(sizeof(devide_text_t));
    devide->text = rpg->player->lore_text;
    devide->max_len = 65;
    devide->pos = (sfVector2f){view_pos.x - 105, view_pos.y - 70};
    devide->color = sfBlack;
    devide->line_spaces = 10;
    divide_a_text(rpg, devide);
    free(devide);
    check_popup_lore(rpg);
}
