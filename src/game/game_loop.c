/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** game_loop
*/

#include "rpg.h"

void game_loop(rpg_t *rpg)
{
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
