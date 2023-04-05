/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_quests
*/

#include "rpg.h"

static void draw_quest_box(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(rpg->player->view);
    sfVector2f view_size = sfView_getSize(rpg->player->view);

    sfSprite_setPosition(RPA->quests_box,
        (sfVector2f){view_pos.x + view_size.x / 2 - 10,
        view_pos.y - view_size.y / 2 + 10});
    sfRenderWindow_drawSprite(rpg->glib->window->window, RPA->quests_box, NULL);
}

static void draw_quest_text(char *quest_id, rpg_t *rpg, int i)
{
    quest_t *quest = get_quest(rpg, quest_id);
    sfVector2f view_pos = sfView_getCenter(rpg->player->view);
    sfVector2f view_size = sfView_getSize(rpg->player->view);
    sfVector2f pos = (sfVector2f){view_pos.x + view_size.x / 2 - 83,
        view_pos.y - view_size.y / 2 + 25};
    sfText *text = sfText_create();

    sfText_setString(text, quest->name);
    sfText_setFont(text, gl_get_font(rpg->glib, MINECRAFT_FONT));
    sfText_setScale(text, (sfVector2f){0.1, 0.1});
    sfText_setCharacterSize(text, 70);
    sfText_setPosition(text, (sfVector2f){pos.x, pos.y + 15 * i});
    sfRenderWindow_drawText(rpg->glib->window->window, text, NULL);
    sfText_destroy(text);
}

static void draw_quest_icon(char *quest_id, rpg_t *rpg, int i)
{
    quest_t *quest = get_quest(rpg, quest_id);
    sfVector2f view_pos = sfView_getCenter(rpg->player->view);
    sfVector2f view_size = sfView_getSize(rpg->player->view);
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
}

void draw_quests(rpg_t *rpg)
{
    if (rpg->quests_in_progress[1] == NULL)
        return;
    draw_quest_box(rpg);
    for (int i = 0; rpg->quests_in_progress[i] != NULL; i++) {
        if (get_quest(rpg, rpg->quests_in_progress[i]) == NULL)
            continue;
        draw_quest_text(rpg->quests_in_progress[i], rpg, i - 1);
        draw_quest_icon(rpg->quests_in_progress[i], rpg, i - 1);
    }
}
