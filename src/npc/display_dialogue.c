/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** display_dialogue
*/

#include "rpg.h"

static int get_mid_char(const char *str)
{
    int i = 0;
    int len = 0;

    for (; str[i] != '\0'; i++)
        len++;
    return (len / 2);
}

static void display_dialogue_choice_one(
    rpg_t *rpg,
    sfVector2f view_pos,
    int mid
)
{
    int id = get_key_id(RPK->choice_one.key, rpg);
    sfText *choice_one_text = gl_get_text(rpg->glib,
        PLAYER_DIALOGUE_CHOICE_ONE_TEXT);

    sfText_setPosition(choice_one_text,
        (sfVector2f){view_pos.x - mid * 3, view_pos.y + 125});
    sfRenderWindow_drawText(RGW->window, choice_one_text, NULL);
    if (id != -1) {
        sfSprite_setPosition(RPA->key_sprite[id],
            (sfVector2f) {view_pos.x - mid * 3 - 10, view_pos.y + 129});
        sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id], NULL);
    }
}

static void display_dialogue_choice_two(
    rpg_t *rpg,
    sfVector2f view_pos,
    int mid
)
{
    int id = get_key_id(RPK->choice_one.key, rpg);
    sfText *choice_one_text = gl_get_text(rpg->glib,
        PLAYER_DIALOGUE_CHOICE_ONE_TEXT);

    sfText_setPosition(choice_one_text,
        (sfVector2f){view_pos.x - mid * 3, view_pos.y + 125});
    sfRenderWindow_drawText(RGW->window, choice_one_text, NULL);
    if (id != -1) {
        sfSprite_setPosition(RPA->key_sprite[id],
            (sfVector2f) {view_pos.x - mid * 3 - 10, view_pos.y + 129});
        sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id], NULL);
    }
}

void display_dialogue(rpg_t *rpg)
{
    sfText *main_text = gl_get_text(rpg->glib, PLAYER_DIALOGUE_TEXT);
    sfVector2f view_pos = sfView_getCenter(rpg->player->view);
    const char *str = sfText_getString(main_text);
    int mid = get_mid_char(str);

    if (rpg->player->in_dialogue == 0)
        return;
    sfText_setPosition(main_text,
        (sfVector2f){view_pos.x - mid * 3, view_pos.y + 100});
    sfRenderWindow_drawText(RGW->window, main_text, NULL);
    display_dialogue_choice_one(rpg, view_pos, mid);
}
