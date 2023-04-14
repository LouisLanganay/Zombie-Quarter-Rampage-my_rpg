/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_quests_ig
*/

#include "rpg.h"

static void draw_quest_text(char *quest_id, rpg_t *rpg, int i, int nb_text)
{
    quest_t *quest = get_quest(rpg, quest_id);
    sfVector2f vp = sfView_getCenter(rpg->player->view->view);
    sfVector2f vs = sfView_getSize(rpg->player->view->view);
    sfVector2f pos = (sfVector2f){vp.x + vs.x / 5 + 5, vp.y - vs.y / 2 + 40};
    sfText *text = sfText_create();

    sfText_setString(text, get_language(rpg, quest->name, RSG));
    sfText_setFont(text, gl_get_font(rpg->glib, MINECRAFT_FONT));
    sfText_setScale(text, (sfVector2f){0.1, 0.1});
    sfText_setCharacterSize(text, 70);
    sfText_setPosition(text,
        (sfVector2f){pos.x, pos.y + 15 * i + (12 * nb_text)});
    sfRenderWindow_drawText(rpg->glib->window->window, text, NULL);
    sfText_destroy(text);
}

static void draw_quest_icon(char *quest_id, rpg_t *rpg, int i, int nb_text)
{
    quest_t *quest = get_quest(rpg, quest_id);
    sfVector2f vp = sfView_getCenter(rpg->player->view->view);
    sfVector2f vs = sfView_getSize(rpg->player->view->view);
    sfVector2f pos = (sfVector2f){vp.x + vs.x / 5 - 7, vp.y - vs.y / 2 + 40};

    if (my_strcmp(quest->type, "go_to") == 0) {
        sfSprite_setPosition(RPAQ->go_to,
            (sfVector2f){pos.x, pos.y + 15 * i + (12 * nb_text)});
        sfRenderWindow_drawSprite(rpg->glib->window->window, RPAQ->go_to, NULL);
    }
    if (my_strcmp(quest->type, "talk") == 0) {
        sfSprite_setPosition(RPAQ->talk,
            (sfVector2f){pos.x, pos.y + 15 * i + (12 * nb_text)});
        sfRenderWindow_drawSprite(rpg->glib->window->window, RPAQ->talk, NULL);
    }
    if (my_strcmp(quest->type, "collect") == 0) {
        sfSprite_setPosition(RPAQ->collect,
            (sfVector2f){pos.x, pos.y + 15 * i + (12 * nb_text)});
        sfRenderWindow_drawSprite(RGW->window, RPAQ->collect, NULL);
    }
}

void draw_quests_inv(rpg_t *rpg)
{
    quest_t *quest = NULL;
    sfVector2f vp = sfView_getCenter(rpg->player->view->view);
    sfVector2f vs = sfView_getSize(rpg->player->view->view);
    sfVector2f pos = (sfVector2f){vp.x + vs.x / 5 - 7, vp.y - vs.y / 2 + 40};
    devide_text_t *devide = malloc(sizeof(devide_text_t));
    int nb_text = 0;
    int count = 0;
    for (int i = 0; rpg->quests_in_progress[i] != NULL; i++) {
        if (get_quest(rpg, rpg->quests_in_progress[i]) == NULL) continue;
        quest = get_quest(rpg, rpg->quests_in_progress[i]);
        draw_quest_text(rpg->quests_in_progress[i], rpg, i - 1, count);
        draw_quest_icon(rpg->quests_in_progress[i], rpg, i - 1, count);
        devide->text = get_language(rpg, quest->description, RSG);
        devide->pos = (sfVector2f){pos.x, pos.y + 15 * i + (12 * count)};
        devide->color = sfWhite;
        devide->max_len = 43;
        devide->line_spaces = 10;
        divide_a_text(rpg, devide);
        nb_text = my_strlen(quest->description) / devide->max_len + 1;
        count += nb_text;
    }
}
