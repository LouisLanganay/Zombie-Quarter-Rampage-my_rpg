/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_inventory_popup
*/

#include "rpg.h"

static void init_inventory_popup_text(rpg_t *rpg)
{
    text_t *my_text = malloc(sizeof(text_t));
    my_text->id = INVENTORY_ITEM_POPUP;
    my_text->pos = (sfVector2f){0, 0};
    my_text->font = gl_get_font(rpg->glib, MINECRAFT_FONT);
    my_text->scale = (sfVector2f){0.1, 0.1};
    my_text->color = sfWhite;
    my_text->string = "aaaaaa";
    my_text->size = 50;
    gl_create_text(rpg->glib, my_text);
}

void init_inventory_popup(rpg_t *rpg)
{
    RPI->popup = malloc(sizeof(inv_popup_t));
    RPI->popup->item_name = NULL;
    RPI->popup->action = ADD;
    RPI->popup->clock = sfClock_create();
    RPI->popup->clock2 = sfClock_create();
    init_inventory_popup_text(rpg);
}
