/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** game_loop
*/

#include "rpg.h"

void game_loop(rpg_t *rpg)
{
    sfVector2f screen_size = (sfVector2f){
        rpg->glib->window->mode.width,
        rpg->glib->window->mode.height
    };
    if (rpg->game_state == PAUSE) {
        sfRenderWindow_setView(RGWW, sfRenderWindow_getDefaultView(RGWW));
        draw_menu(rpg);
        return;
    }
    set_view_on_player(rpg);
    draw_map(rpg->maps, rpg->actual_map, rpg);
    display_dialogue(rpg);
    draw_popup_lore(rpg);
    check_narative_popup(rpg);
    draw_inventory(rpg);
    check_sounds(rpg);
    draw_quests(rpg);
    draw_hud(rpg);
}
