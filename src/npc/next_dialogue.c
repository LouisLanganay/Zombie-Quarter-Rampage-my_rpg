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

static void change_texts(rpg_t *rpg, dialog_t *next)
{
    sfText *choice_one_text = gl_get_text(rpg->glib,
        PLAYER_DCHOICE_ONE_TEXT);
    sfText *choice_two_text = gl_get_text(rpg->glib,
        PLAYER_DCHOICE_TWO_TEXT);
    sfText *main_text = gl_get_text(rpg->glib, PLAYER_DIALOGUE_TEXT);

    sfText_setString(main_text, get_language(rpg, next->text, RSG));
    if (next->options == NULL) {
        sfText_setString(choice_one_text, NULL);
        sfText_setString(choice_two_text, NULL);
        return;
    }
    sfText_setString(choice_one_text,
        get_language(rpg, next->options[0]->text, RSG));
    sfText_setString(choice_two_text,
        get_language(rpg, next->options[1]->text, RSG));
}

static char **get_new_arr(rpg_t *rpg, npc_t *npc)
{
    int size = my_arrlen(rpg->save->npc_interactions);
    char **new_arr = malloc(sizeof(char *) * (size + 2));

    for (int i = 0; i < size; i++)
        new_arr[i] = my_strdup(rpg->save->npc_interactions[i]);
    new_arr[size] = my_strdup(npc->name);
    new_arr[size + 1] = NULL;

    return new_arr;
}

void next_dialogue(rpg_t *rpg, int choice)
{
    npc_t *npc = rpg->actual_npc;
    dialog_t *tmp = rpg->actual_npc->dialogs;
    dialog_t *actual = rpg->actual_dialog;
    dialog_t *next = get_dialogue(tmp, actual, choice);

    if (next == NULL) {
        if (my_strcmp(actual->name, "default") != 0)
            rpg->save->npc_interactions = get_new_arr(rpg, npc);
        check_dialogue_function(rpg, actual);
        rpg->player->in_dialogue = 0;
        zoom_view(rpg, 1.001, 20);
        while (sfKeyboard_isKeyPressed(RPK->escape.key) == sfTrue);
        return;
    }
    change_texts(rpg, next);
    rpg->actual_dialog = next;

}
