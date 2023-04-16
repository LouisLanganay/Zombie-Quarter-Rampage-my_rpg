/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save
*/

#include "rpg.h"

void save(rpg_t *rpg)
{
    save_settings(rpg);
    save_game(rpg);
    save_player(rpg);
    save_quests_in_progress(rpg);
    save_quests_completed(rpg);
    save_npc_interactions(rpg);
    save_chests_opened(rpg);
}
