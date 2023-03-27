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
    rpg->debug = (ac == 2 && av[1][0] == '-' && av[1][1] == 'd') ? 1 : 0;
    create_map(rpg, "resources/maps/main_map.json");
    init_glib(rpg);
    init_player(rpg);

    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        print_framerate();
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        set_view_on_player(rpg);
        gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
        draw_map(rpg->maps, "resources/maps/main_map.json", rpg);
        sfRenderWindow_display(rpg->glib->window->window);
    }
}
