/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_paper_music
*/


#include "rpg.h"

void i_paper_music(rpg_t *rpg, sfVector2f pos)
{
    sfVector2f pos2 = {pos.x - 160, pos.y + 10};
    char *str = get_language(rpg, "house_paper_interact", RSG);
    draw_interaction_popup(rpg, pos2, RPK->interact.key, str);

}
