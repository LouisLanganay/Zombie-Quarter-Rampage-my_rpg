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
    gl_button_change_state(BTN_SAVEBTN, rpg->glib->buttons, sfTrue);
    gl_button_change_state(BTN_LOAD, rpg->glib->buttons, sfTrue);
    gl_button_change_state(BTN_SEETING, rpg->glib->buttons, sfTrue);
}

void game_loop(rpg_t *rpg)
{
    if (rpg->game_state == PAUSE) {
        sfRenderWindow_setView(RGWW, sfRenderWindow_getDefaultView(RGWW));
        draw_menu(rpg);
        return;
    }
    disables_buttons(rpg);
    set_view_on_player(rpg);
    draw_map(rpg->maps, rpg->actual_map, rpg);
    check_shader(rpg);
    display_dialogue(rpg);
    draw_popup_lore(rpg);
    draw_inventory(rpg);
    check_narative_popup(rpg);
    check_sounds(rpg);
    draw_quests(rpg);
    draw_hud(rpg);
    draw_item_popup(rpg);
    hunger_lost(rpg);
    check_game_lost(rpg);
    draw_game_lost_screen(rpg);
}
