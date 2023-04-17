/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** jack_friend
*/

#include "rpg.h"

void jack_friend(rpg_t *rpg, sfVector2f pos)
{
    map_t *map = get_map(rpg, rpg->actual_map);
    npc_t *npc = get_npc(map, "Guillaume");

    if (my_arr_contains(rpg->save->npc_interactions, npc->name) == 1 &&
        npc->default_dialog == NULL)
        return;
    draw_interaction_popup(rpg,
        (sfVector2f){pos.x - 40, pos.y + 20},
        RPK->interact.key, get_language(rpg, "jackfriend_interact", RSG));
    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue)
        start_dialogue(rpg, npc);
}
