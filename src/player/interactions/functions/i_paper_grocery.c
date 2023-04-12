/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_paper_grocery
*/

#include "rpg.h"

void i_paper_grocery(rpg_t *rpg, sfVector2f pos)
{
    char *str = NULL;
    str = get_language(rpg, "paper_interact", RSG);
    draw_interaction_popup(rpg, (sfVector2f){pos.x - 165, pos.y + 15},
        RPK->interact.key, str);
    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue) {
        while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
        rpg->player->lore_text = my_strdup(get_language(rpg,
            "grocery_paper", RSG));
        rpg->player->lore_open = 1;
    }
}
