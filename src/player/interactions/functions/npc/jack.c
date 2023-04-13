/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** jack
*/

#include "rpg.h"

void jack(rpg_t *rpg, sfVector2f pos)
{
    map_t *map = get_map(rpg, rpg->actual_map);
    npc_t *npc = get_npc(map, "Jack");

    if (my_arr_contains(rpg->save->npc_interactions, npc->name) == 1 &&
        npc->default_dialog == NULL)
        return;
    draw_interaction_popup(rpg,
        (sfVector2f){pos.x - 35, pos.y + 20},
        RPK->interact.key, get_language(rpg, "jack_interact", RSG));
    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue)
        start_dialogue(rpg, npc);
}
