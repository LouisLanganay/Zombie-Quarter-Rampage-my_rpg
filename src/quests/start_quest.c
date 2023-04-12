/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_quest
*/

#include "rpg.h"

static int arr_len(char **arr)
{
    int i = 0;

    while (arr[i] != NULL) i++;
    return (i);
}

static char **add_item_to_arr(char **arr, char *item)
{
    char **new_arr = malloc(sizeof(char *) * (arr_len(arr) + 2));
    int i = 0;

    while (arr[i] != NULL) {
        new_arr[i] = arr[i];
        i++;
    }
    new_arr[i] = item;
    new_arr[i + 1] = NULL;
    return (new_arr);
}

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
