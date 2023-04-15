/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_narative_popup
*/

#include "rpg.h"

void start_narative_popup(rpg_t *rpg)
{
    sfClock_restart(rpg->narative->clock);
    sfText_setString(rpg->narative->text, rpg->narative->str);
}
