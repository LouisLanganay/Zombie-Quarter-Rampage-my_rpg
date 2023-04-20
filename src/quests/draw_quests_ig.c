/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_quests_ig
*/

#include "rpg.h"

static void draw_quest_text(char *quest_id, rpg_t *rpg, int i)
{
    quest_t *quest = get_quest(rpg, quest_id);
    sfVector2f view_pos = sfView_getCenter(rpg->player->view->view);
    sfVector2f view_size = sfView_getSize(rpg->player->view->view);
    sfVector2f pos = (sfVector2f){view_pos.x + view_size.x / 2 - 83,
        view_pos.y - view_size.y / 2 + 25};
    devide_text_t *devide = malloc(sizeof(devide_text_t));
    devide->pos = (sfVector2f){pos.x, pos.y + 15 * i};
    devide->text = get_language(rpg, quest->name, RSG);
    devide->color = sfWhite;
    devide->max_len = 18;
    devide->line_spaces = 6;
    if (devide->text == NULL)
        return;
    divide_a_text(rpg, devide);
}

static void draw_quest_icon(char *quest_id, rpg_t *rpg, int i)
{
    quest_t *quest = get_quest(rpg, quest_id);
    sfVector2f view_pos = sfView_getCenter(rpg->player->view->view);
    sfVector2f view_size = sfView_getSize(rpg->player->view->view);
    sfVector2f pos = (sfVector2f){view_pos.x + view_size.x / 2 - 95,
        view_pos.y - view_size.y / 2 + 25};

    if (my_strcmp(quest->type, "go_to") == 0) {
        sfSprite_setPosition(RPAQ->go_to, (sfVector2f){pos.x, pos.y + 15 * i});
        sfRenderWindow_drawSprite(rpg->glib->window->window, RPAQ->go_to, NULL);
    }
    if (my_strcmp(quest->type, "talk") == 0) {
        sfSprite_setPosition(RPAQ->talk, (sfVector2f){pos.x, pos.y + 15 * i});
        sfRenderWindow_drawSprite(rpg->glib->window->window, RPAQ->talk, NULL);
    }
    if (my_strcmp(quest->type, "collect") == 0) {
        sfSprite_setPosition(RPAQ->collect,(sfVector2f){pos.x, pos.y + 15 * i});
        sfRenderWindow_drawSprite(RGW->window, RPAQ->collect, NULL);
    }
}

void draw_quests_ig(rpg_t *rpg)
{
    int id = get_key_id(RPK->inventory.key, rpg);
    sfVector2f view_pos = sfView_getCenter(rpg->player->view->view);
    sfVector2f view_size = sfView_getSize(rpg->player->view->view);
    sfVector2f pos = (sfVector2f){view_pos.x + view_size.x / 2 - 100,
        view_pos.y - view_size.y / 2 + 100};

    for (int i = 0; rpg->quests_in_progress[i] != NULL; i++) {
        if (get_quest(rpg, rpg->quests_in_progress[i]) == NULL)
            continue;
        draw_quest_text(rpg->quests_in_progress[i], rpg, i - 1);
        draw_quest_icon(rpg->quests_in_progress[i], rpg, i - 1);
    }

    if (id != -1) {
        sfSprite_setScale(RPA->key_sprite[id], (sfVector2f){1.3, 1.3});
        sfSprite_setPosition(RPA->key_sprite[id], pos);
        sfRenderWindow_drawSprite(RGW->window, RPA->key_sprite[id], NULL);
        sfSprite_setScale(RPA->key_sprite[id], (sfVector2f){1, 1});
    }
}
