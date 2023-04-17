/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_rpg
*/

#include "rpg.h"

void init_rpg(rpg_t *rpg, int ac, char **av)
{
    rpg->debug = (ac == 2 && av[1][0] == '-' && av[1][1] == 'd') ? 1 : 0;
    rpg->actual_map = "resources/maps/main_map.json";
    rpg->actual_dialog = malloc(sizeof(dialog_t));
    rpg->actual_npc = malloc(sizeof(npc_t));
    rpg->game_state = MENU;
    rpg->maps_loaded = 0;
    rpg->shader = init_shader();
    init_combat_history(rpg);
}
