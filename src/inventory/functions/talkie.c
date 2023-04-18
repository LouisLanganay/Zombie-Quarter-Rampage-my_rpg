/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** talkie
*/

#include "rpg.h"

void talkie(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    if (RSG == FR)
        gl_play_sound(rpg->glib, TALKIEFR_SOUND_ID);
    else
        gl_play_sound(rpg->glib, TALKIEEN_SOUND_ID);
    rpg->narative->str = get_language(rpg, "talkie_str", RSG);
    start_narative_popup(rpg);
    if (quest_is_completed(rpg, "run_away") == 0 &&
        quest_is_in_progress(rpg, "run_away") == 0)
        start_quest(rpg, "run_away");
}
