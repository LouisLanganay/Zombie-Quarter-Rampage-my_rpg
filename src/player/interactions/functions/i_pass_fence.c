/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_pass_fence
*/

#include "rpg.h"

static void pass_fence(rpg_t *rpg)
{
    if (rpg->player->pos.y > 275)
        rpg->player->pos.y = 16 * 16;
    if (rpg->player->pos.y < 256)
        rpg->player->pos.y = 19 * 16;
}

void i_pass_fence(rpg_t *rpg, sfVector2f pos)
{
    char *str = get_language(rpg, "pass_fence_interaction", RSG);
    draw_interaction_popup(rpg, (sfVector2f){pos.x - 100, pos.y - 10},
        RPK->interact.key, str);

    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue)
        pass_fence(rpg);
    while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
}
