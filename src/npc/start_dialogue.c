/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_dialogue
*/

#include "rpg.h"

static void edit_save(rpg_t *rpg, npc_t *npc)
{
    int size = my_arrlen(rpg->save->npc_interactions);
    char **new_arr = NULL;

    if (npc->one_time != 1) return;

    new_arr = malloc(sizeof(char *) * (size + 2));

    for (int i = 0; i < size; i++)
        new_arr[i] = my_strdup(rpg->save->npc_interactions[i]);
    new_arr[size] = my_strdup(npc->name);
    new_arr[size + 1] = NULL;
    free(rpg->save->npc_interactions);
    rpg->save->npc_interactions = new_arr;
}

void start_dialogue(rpg_t *rpg, npc_t *npc)
{
    sfText *main_text = gl_get_text(rpg->glib, PLAYER_DIALOGUE_TEXT);
    sfText *choice_one_text = gl_get_text(rpg->glib, PLAYER_DCHOICE_ONE_TEXT);
    sfText *choice_two_text = gl_get_text(rpg->glib,
        PLAYER_DCHOICE_TWO_TEXT);
    dialog_t *dialog = npc->dialogs;

    if (rpg->player->in_dialogue != 0) return;
    if (npc->one_time == 1 && my_arr_contains(RSNI, npc->name) == 1)
        return;
    else
        edit_save(rpg, npc);
    while (dialog) {
        if (my_strcmp(dialog->name, "discovery") == 0) break;
        dialog = dialog->next;
    }
    sfText_setString(main_text, dialog->text);
    sfText_setString(choice_one_text, dialog->options[0]->text);
    sfText_setString(choice_two_text, dialog->options[1]->text);
    rpg->player->in_dialogue = 1;
    rpg->actual_dialog = dialog;
    rpg->actual_npc = npc;
}
