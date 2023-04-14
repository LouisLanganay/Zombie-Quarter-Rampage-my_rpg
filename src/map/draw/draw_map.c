/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_map
*/

#include "rpg.h"

void draw_map(map_t *maps, char *to_find, rpg_t *rpg)
{
    map_t *tmp = maps;
    while (tmp != NULL) {
        if (my_strcmp(tmp->map_path, to_find) == 0) {
            draw_layer_by_class(tmp, rpg, "down");
            draw_layer_by_order(tmp, rpg, 0);
            draw_player(rpg);
            draw_layer_by_order(tmp, rpg, 1);
            draw_layer_by_class(tmp, rpg, "top");
            return;
        }
        tmp = tmp->next;
    }
}
