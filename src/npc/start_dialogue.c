/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_dialogue
*/

#include "rpg.h"

void start_dialogue(rpg_t *rpg, npc_t *npc)
{
    sfText *main_text = gl_get_text(rpg->glib, PLAYER_DIALOGUE_TEXT);
    sfText *choice_one_text = gl_get_text(rpg->glib,
        PLAYER_DIALOGUE_CHOICE_ONE_TEXT);
    sfText *choice_two_text = gl_get_text(rpg->glib,
        PLAYER_DIALOGUE_CHOICE_TWO_TEXT);
    dialog_t *dialog = npc->dialogs;

    if (rpg->player->in_dialogue != 0)
        return;

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
