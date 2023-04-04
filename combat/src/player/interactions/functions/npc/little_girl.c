/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** little_girl
*/

#include "rpg.h"

void little_girl(rpg_t *rpg, sfVector2f pos)
{
    map_t *map = get_map(rpg, rpg->actual_map);
    npc_t *npc = get_npc(map, "Annia");
    draw_interaction_popup(rpg,
        (sfVector2f){pos.x - 25, pos.y + 20},
        RPK->interact.key, "talk to her.");
    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue)
        start_dialogue(rpg, npc);
}
