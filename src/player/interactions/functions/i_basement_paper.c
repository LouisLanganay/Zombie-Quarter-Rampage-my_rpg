/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_basement_paper
*/

#include "rpg.h"

void i_basement_paper(rpg_t *rpg, sfVector2f pos)
{
    sfVector2f pos2 = {pos.x - 100, pos.y + 30};
    char *str = get_language(rpg, "paper_interact", RSG);
    draw_interaction_popup(rpg, pos2, RPK->interact.key, str);

    if (sfKeyboard_isKeyPressed(RPK->interact.key)) {
        while (sfKeyboard_isKeyPressed(RPK->interact.key));
        rpg->player->lore_text = my_strdup(get_language(rpg,
            "basement_paper", RSG));
        rpg->player->lore_open = 1;
    }
}
