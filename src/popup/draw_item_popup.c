/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_item_popup
*/

#include "rpg.h"

static void draw_item_popup_annimate(rpg_t *rpg)
{
    sfVector2f pos = sfView_getCenter(RP->view->view);
    int mc = get_mid_char(RPI->popup->item_name);
    sfText *text = gl_get_text(rpg->glib, INVENTORY_ITEM_POPUP);
    time_t time = sfClock_getElapsedTime(RPI->popup->clock).microseconds;
    float seconds = time / 1000000.0;
    int posy = (sfView_getCenter(RP->view->view).y + 160) - RPI->popup->posy;

    if (seconds > 0.001) {
        if (RPI->popup->posy < 20)
            RPI->popup->posy += 1;
        sfClock_restart(RPI->popup->clock);
    }
    sfText_setPosition(text, (sfVector2f){pos.x - mc * 2.65, posy});
    time = sfClock_getElapsedTime(RPI->popup->clock2).microseconds;
    seconds = time / 1000000.0;
    if ((seconds > 4 && RPI->popup->next == NULL) ||
        (seconds > 1.5 && RPI->popup->next != NULL))
        remove_first_item_popup(rpg);
}

static void reset_clocks(rpg_t *rpg, inv_popup_t *popup)
{
    sfText *text = gl_get_text(rpg->glib, INVENTORY_ITEM_POPUP);
    sfVector2f poss = sfView_getCenter(RP->view->view);
    int mid_char = get_mid_char(popup->item_name);

    if (popup->start == 0) {
        sfClock_restart(popup->clock);
        sfClock_restart(popup->clock2);
        sfText_setPosition(text,
        (sfVector2f){poss.x - mid_char * 2.65, poss.y + 160});
        popup->start = 1;
    }
}

void draw_item_popup(rpg_t *rpg)
{
    if (RPI->popup == NULL) return;
    sfText *text = gl_get_text(rpg->glib, INVENTORY_ITEM_POPUP);

    reset_clocks(rpg, RPI->popup);
    if (RPI->popup->action == ADD) {
        sfText_setString(text, my_strcat_malloc("+", RPI->popup->item_name));
        sfText_setColor(text, (sfColor){0, 255, 0, 255});
    } else {
        sfText_setString(text, my_strcat_malloc("-", RPI->popup->item_name));
        sfText_setColor(text, (sfColor){255, 0, 0, 255});
    }
    draw_item_popup_annimate(rpg);
    gl_draw_text(rpg->glib, INVENTORY_ITEM_POPUP);
}
