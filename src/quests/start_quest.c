/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_quest
*/

#include "rpg.h"

void start_quest(rpg_t *rpg, char *id)
{
    quest_t *quest = rpg->quests;

    while (quest != NULL) {
        if (my_strcmp(quest->id, id) == 0) break;
        quest = quest->next;
    }
    if (quest == NULL) return;
    sfSound_setVolume(gl_get_sound(rpg->glib, XP_SOUND_ID)->sound, (RSV * 0.1));
    gl_play_sound(rpg->glib, XP_SOUND_ID);
    rpg->quests_in_progress = add_item_to_arr(rpg->quests_in_progress,
        quest->id);
}
