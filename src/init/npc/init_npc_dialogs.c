/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_npc_dialogs
*/

#include "rpg.h"

static int count_options(parsed_data_t *arr)
{
    int i = 0;

    while (arr != NULL) {
        i++;
        arr = arr->next;
    }
    return i;
}

static void add_options(dialog_t *dialog, parsed_data_t *arr, rpg_t *rpg)
{
    (void)rpg;
    int count = count_options(arr);
    dialog->options = malloc(sizeof(dialog_option_t) * (count + 1));

    for (int i = 0; i < count; i++) {
        dialog->options[i] = malloc(sizeof(dialog_option_t));
        dialog->options[i]->text = jp_search(arr->value.p_obj,
            "text")->value.p_str;
        dialog->options[i]->next_dialog = jp_search(arr->value.p_obj,
            "next")->value.p_str;
        arr = arr->next;
    }
    dialog->options[count] = NULL;
}

static void add_dialog(npc_t *npc, parsed_data_t *obj, rpg_t *rpg)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));
    dialog->name = jp_search(obj, "name")->value.p_str;
    dialog->text = jp_search(obj, "text")->value.p_str;
    if (jp_search(obj, "function")->type != p_null)
        dialog->function = jp_search(obj, "function")->value.p_str;
    else
        dialog->function = NULL;
    if (jp_search(obj, "options")->type != p_null)
        add_options(dialog, jp_search(obj, "options")->value.p_arr, rpg);
    else
        dialog->options = NULL;
    dialog->next = npc->dialogs;
    npc->dialogs = dialog;
}

void init_npc_dialogs(npc_t *npc, parsed_data_t *dialogs_arr, rpg_t *rpg)
{
    npc->dialogs = NULL;
    while (dialogs_arr != NULL) {
        add_dialog(npc, dialogs_arr->value.p_obj, rpg);
        dialogs_arr = dialogs_arr->next;
    }
}
