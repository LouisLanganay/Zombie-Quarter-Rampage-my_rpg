/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_quests
*/

#include "rpg.h"

static void draw_quest_box(rpg_t *rpg)
{
    sfVector2f view_pos = sfView_getCenter(rpg->player->view->view);
    sfVector2f view_size = sfView_getSize(rpg->player->view->view);

    sfSprite_setPosition(RPA->quests_box,
        (sfVector2f){view_pos.x + view_size.x / 2 - 10,
        view_pos.y - view_size.y / 2 + 10});
    sfRenderWindow_drawSprite(rpg->glib->window->window, RPA->quests_box, NULL);
}

void draw_quests(rpg_t *rpg)
{
    if (rpg->quests_in_progress[1] == NULL)
        return;
    if (rpg->player->inventory->is_open == 1)
        sfSprite_setScale(RPA->quests_box, (sfVector2f){4, 4});
    else
        sfSprite_setScale(RPA->quests_box, (sfVector2f){2, 2});
    draw_quest_box(rpg);
    if (rpg->player->inventory->is_open == 0)
        draw_quests_ig(rpg);
    else
        draw_quests_inv(rpg);
}
