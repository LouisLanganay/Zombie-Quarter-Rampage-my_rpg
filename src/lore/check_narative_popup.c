/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_narative_popup
*/

#include "rpg.h"

void check_narative_popup(rpg_t *rpg)
{
    time_t time = sfClock_getElapsedTime(rpg->narative->clock).microseconds;
    float seconds = time / 1000000.0;
    sfVector2f pos = sfView_getCenter(rpg->player->view);
    int mid_char = get_mid_char(rpg->narative->str);

    if (rpg->narative->str == NULL)
        return;

    if (seconds > 6) {
        rpg->narative->str = NULL;
        sfText_setString(rpg->narative->text, rpg->narative->str);
        sfClock_restart(rpg->narative->clock);
    }
    if (rpg->narative->str != NULL) {
        sfText_setPosition(rpg->narative->text,
            (sfVector2f){pos.x - mid_char * 2.65, pos.y + 120});
        sfRenderWindow_drawText(RGW->window, rpg->narative->text, NULL);
    }
}
