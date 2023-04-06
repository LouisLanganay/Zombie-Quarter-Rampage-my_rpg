/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_house_paper
*/

#include "rpg.h"

void i_house_paper(rpg_t *rpg, sfVector2f pos)
{
    sfVector2f pos2 = {pos.x - 28, pos.y + 10};
    char *str = get_language(rpg, "house_paper_interact", RSG);
    draw_interaction_popup(rpg, pos2, RPK->interact.key, str);
    if (sfKeyboard_isKeyPressed(rpg->player->keys->interact.key) == sfTrue) {
        rpg->player->lore_text = my_strdup(get_language(rpg, "house_paper", RSG));
        rpg->player->lore_open = 1;
    }
}
