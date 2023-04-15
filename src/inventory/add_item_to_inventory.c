/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** add_item_to_inventory
*/

#include "rpg.h"

int add_item_to_inventory(int id, rpg_t *rpg)
{
    int i = 0;

    while (RPI->items[i] != -1)
        i++;
    if (i > INVENTORY_SIZE)
        return -1;
    RPI->items[i] = id;
    sfVector2f poss = sfView_getCenter(RP->view->view);
    RPI->popup->item_name = get_language(rpg,
        get_item_name(RPI->items[i]), RSG);
    RPI->popup->action = ADD;
    int mid_char = get_mid_char(RPI->popup->item_name);
    sfText *text = gl_get_text(rpg->glib, INVENTORY_ITEM_POPUP);

    sfText_setPosition(text,
        (sfVector2f){poss.x - mid_char * 2.65, poss.y + 160});
    sfClock_restart(RPI->popup->clock);
    sfClock_restart(RPI->popup->clock2);
    return id;
}
