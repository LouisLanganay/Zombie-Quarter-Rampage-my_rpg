/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** handle_inventory_system
*/

#include "rpg.h"
#include "jp.h"

static char *get_description(int id)
{
    parsed_data_t *data = jp_parse("resources/jsons/items.json");
    int tmp;

    if (id == -1)
        return NULL;
    while (data) {
        tmp = jp_search(data->value.p_obj, "id")->value.p_int;
        if (tmp == id)
            return jp_search(data->value.p_obj, "description")->value.p_str;
        data = data->next;
    }
    return NULL;
}

static void display_item_data(rpg_t *rpg, char *name)
{
    devide_text_t *devide = malloc(sizeof(devide_text_t));
    sfVector2f view_pos = sfView_getCenter(RP->view);
    char *description = get_description(RP->inventory->items
    [RP->inventory->pos]);

    sfRenderWindow_drawSprite(rpg->glib->window->window,
    RP->inventory->items_data_sprite, NULL);
    devide->text = get_language(rpg, name, RSG);
    devide->max_len = 35;
    devide->pos = (sfVector2f) {view_pos.x - get_mid_char(devide->text) * 4,
    view_pos.y + 45};
    devide->color = sfBlack;
    divide_a_text(rpg, devide);
    devide->text = get_language(rpg, description, RSG);
    devide->max_len = 35;
    devide->pos = (sfVector2f) {view_pos.x - 65, view_pos.y + 65};
    devide->color = sfBlack;
    divide_a_text(rpg, devide);
    handle_drop_use_button(rpg);
}

void handle_inventory_system(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(RP->view);
    sfVector2f pos_s = {view_pos.x - 74, view_pos.y - 102};
    char *name = get_item_name(RP->inventory->items[RP->inventory->pos]);
    int pos = RP->inventory->pos;

    while (pos > 0) {
        if (pos % 4 == 0) {
            pos_s.y += 35.3;
            pos_s.x -= (35.2 * 3);
        } else
            pos_s.x += 35.2;
        pos--;
    }
    sfSprite_setPosition(RP->inventory->select_sprite, pos_s);
    sfRenderWindow_drawSprite(rpg->glib->window->window,
    RP->inventory->select_sprite, NULL);
    if (rpg->player->inventory->is_data_open != 1 && name != NULL)
        display_item_data(rpg, name);
}
