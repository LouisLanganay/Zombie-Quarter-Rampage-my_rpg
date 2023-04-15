/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** remove_item_to_inventory
*/

#include "rpg.h"

int remove_item_to_inventory(rpg_t *rpg, int pos)
{
    if (RPI->items[pos] == -1)
        return -1;
    sfVector2f poss = sfView_getCenter(RP->view->view);
    RPI->popup->item_name = my_strdup(get_item_name(RPI->items[pos]));
    RPI->popup->action = REMOVE;
    int mid_char = get_mid_char(RPI->popup->item_name);
    sfText *text = gl_get_text(rpg->glib, INVENTORY_ITEM_POPUP);

    sfText_setPosition(text,
       (sfVector2f){poss.x - mid_char * 2.65, poss.y + 160});
    sfClock_restart(RPI->popup->clock);
    sfClock_restart(RPI->popup->clock2);
    RPI->items[pos] = -1;
    return 0;
}
