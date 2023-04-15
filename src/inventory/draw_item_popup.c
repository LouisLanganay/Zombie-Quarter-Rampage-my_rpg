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
    int mid_char = get_mid_char(RPI->popup->item_name);
    sfText *text = gl_get_text(rpg->glib, INVENTORY_ITEM_POPUP);
    time_t time = sfClock_getElapsedTime(RPI->popup->clock).microseconds;
    float seconds = time / 1000000.0;
    int posy = sfText_getPosition(text).y;

    if (seconds > 0.001) {
        if (posy > pos.y + 140) {
            sfText_setPosition(text,
            (sfVector2f){pos.x - mid_char * 2.65, posy - 1});
            sfClock_restart(RPI->popup->clock);
        }
    }
    time = sfClock_getElapsedTime(RPI->popup->clock2).microseconds;
    seconds = time / 1000000.0;
    if (seconds > 4)
        RPI->popup->item_name = NULL;
}

void draw_item_popup(rpg_t *rpg)
{
    sfVector2f pos = sfView_getCenter(RP->view->view);
    int mid_char = get_mid_char(RPI->popup->item_name);
    sfText *text = gl_get_text(rpg->glib, INVENTORY_ITEM_POPUP);

    if (RPI->popup->item_name == NULL) return;

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
