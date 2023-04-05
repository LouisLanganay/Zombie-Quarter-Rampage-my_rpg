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
    init(rpg);

    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        print_framerate();
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        if (rpg->game_started == 1)
            game_loop(rpg);
        else {
            gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
            draw_splash_screen(rpg);
        }
        sfRenderWindow_display(rpg->glib->window->window);
        if (rpg->maps_loaded == 0)
            load_maps(rpg);
    }
}
