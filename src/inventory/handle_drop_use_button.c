/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** handle_drop_use_button
*/

#include "rpg.h"
#include "jp.h"

static void draw_text_use(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(RP->view);
    devide_text_t *devide = malloc(sizeof(devide_text_t));

    devide->text = get_language(rpg, "use_name", RSG);
    devide->max_len = 35;
    devide->pos = (sfVector2f) {view_pos.x + 27,
    view_pos.y + 106};
    devide->color = sfBlack;
    divide_a_text(rpg, devide);
}

static void draw_text_destroy(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(RP->view);
    devide_text_t *devide = malloc(sizeof(devide_text_t));

    devide->text = get_language(rpg, "destroy_name", RSG);
    devide->max_len = 35;
    devide->pos = (sfVector2f) {view_pos.x - 53,
    view_pos.y + 106};
    devide->color = sfBlack;
    divide_a_text(rpg, devide);
}

void handle_drop_use_button(rpg_t *rpg)
{
    int id = get_key_id(RPK->choice_two.key, rpg);
    int id1 = get_key_id(RPK->choice_one.key, rpg);
    sfVector2f view_pos = sfView_getCenter(RP->view);

    if (id != -1) {
        sfSprite_setPosition(RPA->key_sprite[id],
            (sfVector2f) {view_pos.x + 20, view_pos.y + 110});
        draw_text_use(rpg);
        sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id], NULL);
    }
    if (id1 != -1) {
        sfSprite_setPosition(RPA->key_sprite[id1],
            (sfVector2f) {view_pos.x - 60, view_pos.y + 110});
        draw_text_destroy(rpg);
        sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id1], NULL);
    }
}
