/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** remove_first_item_popup
*/

#include "rpg.h"

void remove_first_item_popup(rpg_t *rpg)
{
    inv_popup_t *tmp = rpg->player->inventory->popup;

    if (tmp == NULL)
        return;
    rpg->player->inventory->popup = tmp->next;
    sfClock_destroy(tmp->clock);
    sfClock_destroy(tmp->clock2);
    free(tmp);
}
