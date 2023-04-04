/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "rpg.h"


void event_window_close(window_t *window)
{
    sfRenderWindow_close(window->window);
}

int main(int ac, char **av)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    init_rpg(rpg, ac, av);
    create_map(rpg, "resources/maps/main_map.json");
    create_map(rpg, "resources/maps/player_house.json");
    init_glib(rpg);
    init_language(rpg);
    init_settings(rpg);
    init_player(rpg);
    init_popup_interaction(rpg);
    init_save(rpg);
    init_main_menu(rpg);
    load_save(rpg, "resources/saves/default.json");

    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        print_framerate();
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        gl_button_change_state(BTN_RESUME, rpg->glib->buttons, sfFalse);
        gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
        gl_draw_button(BTN_RESUME, rpg->glib->buttons, rpg->glib->window);
        //set_view_on_player(rpg);
        //gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
        //draw_map(rpg->maps, rpg->actual_map, rpg);
        sfRenderWindow_display(rpg->glib->window->window);
    }
}
