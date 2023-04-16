/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** game_loop
*/

#include "rpg.h"

static void disables_buttons(rpg_t *rpg)
{
    gl_button_change_state(BTN_SAVE1, rpg->glib->buttons, sfTrue);
    gl_button_change_state(BTN_SAVE2, rpg->glib->buttons, sfTrue);
    gl_button_change_state(BTN_SAVE3, rpg->glib->buttons, sfTrue);
}

void game_loop(rpg_t *rpg)
{
    disables_buttons(rpg);
    set_view_on_player(rpg);
    draw_map(rpg->maps, rpg->actual_map, rpg);
    display_dialogue(rpg);
    draw_popup_lore(rpg);
    check_narative_popup(rpg);
    draw_inventory(rpg);
    check_sounds(rpg);
    draw_quests(rpg);
    draw_hud(rpg);
    draw_item_popup(rpg);
    hunger_lost(rpg);
    check_game_lost(rpg);
    draw_game_lost_screen(rpg);
}
