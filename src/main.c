/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "rpg.h"

static void environemental_shader(rpg_t *rpg)
{
    if (global_sec > 120 && global_sec < 180 && my_strcmp(rpg->actual_map,
    "resources/maps/main_map.json") == 0
    && rpg->game_state == GAME) {
        rpg->shader->rain_bool = 1;
    } else
        rpg->shader->rain_bool = 0;
    if (global_sec > 140 && global_sec < 260 &&
    my_strcmp(rpg->actual_map, "resources/maps/main_map.json") == 0
    && rpg->game_state == GAME)
        rpg->shader->torch_bool = 1;
    else
        rpg->shader->torch_bool = 0;
    if (global_sec > 260)
        sfClock_restart(rpg->global_clock);
    if (my_strcmp(rpg->actual_map, "resources/maps/main_map.json") != 0) {
        rpg->shader->rain_bool = 0;
        rpg->shader->torch_bool = 0;
    }
}

int main(int ac, char **av)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    init_rpg(rpg, ac, av);
    init(rpg);
    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        environemental_shader(rpg);
        gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
        if (rpg->game_state == GAME || rpg->game_state == GAME_LOST
            || rpg->game_state == PAUSE || rpg->game_state == GAME_WIN)
            game_loop(rpg);
        if (rpg->game_state == MENU)
            game_start(rpg);
        sfRenderWindow_display(rpg->glib->window->window);
        if (rpg->maps_loaded == 0)
            load_maps(rpg);
        gl_buttons_hovered(rpg->glib->buttons, rpg->glib->window, rpg);
    }
    my_free(rpg);
}
