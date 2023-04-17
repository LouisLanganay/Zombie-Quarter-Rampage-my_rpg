/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** change_dialogue
*/

#include "rpg.h"

static dialog_t *get_dialogue(npc_t *npc, char *id)
{
    dialog_t *tmp = npc->dialogs;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, id) == 0)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

static void start_dialogue_name(rpg_t *rpg, npc_t *npc, char *id)
{
    sfText *main_text = gl_get_text(rpg->glib, PLAYER_DIALOGUE_TEXT);
    sfText *choice_one_text = gl_get_text(rpg->glib, PLAYER_DCHOICE_ONE_TEXT);
    sfText *choice_two_text = gl_get_text(rpg->glib, PLAYER_DCHOICE_TWO_TEXT);
    dialog_t *dialog = get_dialogue(npc, id);

    sfText_setString(main_text, get_language(rpg, dialog->text, RSG));
    if (dialog->options != NULL) {
        sfText_setString(choice_one_text,
            get_language(rpg, dialog->options[0]->text, RSG));
        sfText_setString(choice_two_text,
            get_language(rpg, dialog->options[1]->text, RSG));
    }
    rpg->player->in_dialogue = 1;
    rpg->actual_dialog = dialog;
    rpg->actual_npc = npc;
}

void change_dialogue(rpg_t *rpg, char *id)
{
    start_dialogue_name(rpg, rpg->actual_npc, id);
}
