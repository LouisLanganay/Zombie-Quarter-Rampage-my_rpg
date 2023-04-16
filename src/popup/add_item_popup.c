/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** add_item_popup
*/

#include "rpg.h"

void add_item_popup(rpg_t *rpg, int id, inv_popup_action_t action)
{
    inv_popup_t *new = malloc(sizeof(inv_popup_t));

    printf("Add %s\n", get_item_name(id));
    new->item_name = get_language(rpg, get_item_name(id), RSG);
    new->action = action;
    new->clock = sfClock_create();
    new->clock2 = sfClock_create();
    new->start = 0;
    new->next = rpg->player->inventory->popup;
    rpg->player->inventory->popup = new;
}
