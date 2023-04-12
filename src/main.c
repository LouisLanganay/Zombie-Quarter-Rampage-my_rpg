/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "rpg.h"

int main(int ac, char **av)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    init_rpg(rpg, ac, av);
    init(rpg);
    combat(rpg);

    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        print_framerate();
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        if (rpg->game_started == 1)
            game_loop(rpg);
        else
            game_start(rpg);
        sfRenderWindow_display(rpg->glib->window->window);
        if (rpg->maps_loaded == 0)
            load_maps(rpg);
    }
}
