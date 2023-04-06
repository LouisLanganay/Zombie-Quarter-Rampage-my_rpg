/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** next_dialogue
*/

#include "rpg.h"

static dialog_t *get_dialogue(dialog_t *tmp, dialog_t *actual, int choice)
{
    if (actual->options == NULL)
        return NULL;
    while (tmp != NULL) {
        if (my_strcmp(tmp->name, actual->options[choice]->next_dialog) == 0)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

static void change_main_text(rpg_t *rpg, dialog_t *next)
{
    sfText *main_text = gl_get_text(rpg->glib, PLAYER_DIALOGUE_TEXT);

    sfText_setString(main_text, next->text);
}

static void change_choice_text(rpg_t *rpg, dialog_t *next)
{
    sfText *choice_one_text = gl_get_text(rpg->glib,
        PLAYER_DCHOICE_ONE_TEXT);
    sfText *choice_two_text = gl_get_text(rpg->glib,
        PLAYER_DCHOICE_TWO_TEXT);

    if (next->options == NULL) {
        sfText_setString(choice_one_text, NULL);
        sfText_setString(choice_two_text, NULL);
        return;
    }
    sfText_setString(choice_one_text, next->options[0]->text);
    sfText_setString(choice_two_text, next->options[1]->text);
}

void next_dialogue(rpg_t *rpg, int choice)
{
    npc_t *npc = rpg->actual_npc;
    dialog_t *tmp = rpg->actual_npc->dialogs;
    dialog_t *actual = rpg->actual_dialog;
    dialog_t *next = get_dialogue(tmp, actual, choice);
    parsed_data_t *data = NULL;

    if (next == NULL) {
        if (my_strcmp(actual->name, "default") != 0)
            save_npc_interactions(rpg, npc);
        data = jp_parse(rpg->save->path);
        load_npc_interactions(rpg->save, jp_search(data, "game_timeline"));
        check_dialogue_function(rpg, actual);
        rpg->player->in_dialogue = 0;
        return;
    }
    change_main_text(rpg, next);
    change_choice_text(rpg, next);
    rpg->actual_dialog = next;

}
