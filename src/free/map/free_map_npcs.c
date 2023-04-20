/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** free_map_npcs
*/

#include "rpg.h"

static void free_npc_dialog_options(dialog_t *dialog)
{
    for (int i = 0; dialog->options[i]; i++) {
        free(dialog->options[i]->text);
        free(dialog->options[i]->next_dialog);
        free(dialog->options[i]);
    }
}

static void free_npc_dialogs(npc_t *npc)
{
    dialog_t *tmp = npc->dialogs;
    dialog_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free(tmp->text);
        free(tmp->name);
        free(tmp->function);
        free_npc_dialog_options(tmp);
        free(tmp);
        tmp = next;
    }
}

static void free_npc(npc_t *tmp)
{
    free(tmp->name);
    free(tmp->texture_path);
    free(tmp->default_dialog);
    sfSprite_destroy(tmp->sprite);
    sfTexture_destroy(tmp->texture);
    free_npc_dialogs(tmp);
    sfClock_destroy(tmp->clock);
    free(tmp);
}


void free_map_npcs(map_t *map)
{
    npc_t *tmp = map->npcs;
    npc_t *next = NULL;

    while (tmp) {
        next = tmp->next;
        free_npc(tmp);
        tmp = next;
    }
}
