/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_dialogue
*/

#include "rpg.h"

static void start_dialogue_default(npc_t *npc, rpg_t *rpg)
{
    sfText *main_text = gl_get_text(rpg->glib, PLAYER_DIALOGUE_TEXT);
    sfText *choice_one_text = gl_get_text(rpg->glib, PLAYER_DCHOICE_ONE_TEXT);
    sfText *choice_two_text = gl_get_text(rpg->glib, PLAYER_DCHOICE_TWO_TEXT);
    dialog_t *dialog = npc->dialogs;

    while (dialog) {
        if (my_strcmp(dialog->name, npc->default_dialog) == 0) break;
        dialog = dialog->next;
    }
    sfText_setString(main_text, get_language(rpg, dialog->text, RSG));
    sfText_setString(choice_one_text, NULL);
    sfText_setString(choice_two_text, NULL);
    rpg->player->in_dialogue = 1;
    rpg->actual_dialog = dialog;
    rpg->actual_npc = npc;
}

static void start_dialogue_discovery(npc_t *npc, rpg_t *rpg)
{
    sfText *main_text = gl_get_text(rpg->glib, PLAYER_DIALOGUE_TEXT);
    sfText *choice_one_text = gl_get_text(rpg->glib, PLAYER_DCHOICE_ONE_TEXT);
    sfText *choice_two_text = gl_get_text(rpg->glib, PLAYER_DCHOICE_TWO_TEXT);
    dialog_t *dialog = npc->dialogs;

    while (dialog) {
        if (my_strcmp(dialog->name, "discovery") == 0) break;
        dialog = dialog->next;
    }
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

void start_dialogue(rpg_t *rpg, npc_t *npc)
{
    if (rpg->player->in_dialogue != 0) return;
    zoom_view(rpg, 0.999, 20);
    if (npc->one_time == 1 && my_arr_contains(RSNI, npc->name) == 1)
        start_dialogue_default(npc, rpg);
    else
        start_dialogue_discovery(npc, rpg);

}
