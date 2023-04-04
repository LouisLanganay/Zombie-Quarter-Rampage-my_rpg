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
    init(rpg);
    load_save(rpg, "resources/save.json");

    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        print_framerate();
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        set_view_on_player(rpg);
        gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
        draw_map(rpg->maps, rpg->actual_map, rpg);
        display_dialogue(rpg);
        sfRenderWindow_display(rpg->glib->window->window);
    }
}
