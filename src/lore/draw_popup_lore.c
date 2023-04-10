/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_popup_lore
*/

#include "rpg.h"

void draw_popup_lore(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(rpg->player->view);
    if (rpg->player->lore_open != 1) return;
    sfSprite_setPosition(rpg->player->assets->lore_box,
        (sfVector2f){view_pos.x, view_pos.y});
    sfRenderWindow_drawSprite(rpg->glib->window->window,
        rpg->player->assets->lore_box, NULL);
    draw_interaction_popup(rpg,(sfVector2f){view_pos.x - 105, view_pos.y + 123},
        rpg->player->keys->escape.key, "to close the paper.");
    printf("draw %s\n", rpg->player->lore_text);
    divide_a_text(rpg, rpg->player->lore_text, (sfVector2f){view_pos.x - 85,
        view_pos.y - 50}, sfBlack);
    check_popup_lore(rpg);
}
