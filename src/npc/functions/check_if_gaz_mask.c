/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_if_gaz_mask
*/

#include "rpg.h"

static void check_if_gaz_mask_yes(rpg_t *rpg)
{
    change_dialogue(rpg, "discovery_next_mask");
}

static void check_if_gaz_mask_no(rpg_t *rpg)
{
    rpg->narative->str = get_language(rpg, "no_mask_narative", RSG);
    start_narative_popup(rpg);
}

void check_if_gaz_mask(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    if (check_if_items_is_here(rpg, 31) == 1)
        check_if_gaz_mask_yes(rpg);
    else
        check_if_gaz_mask_no(rpg);
}
