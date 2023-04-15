/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_escape_menu
*/

#include "rpg.h"

void init_escape_menu(rpg_t *rpg)
{
    rpg->background->bg_escape = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->background->bg_escape, (sfVector2f)
    {rpg->glib->window->mode.width, rpg->glib->window->mode.height});
    sfRectangleShape_setFillColor(rpg->background->bg_escape, (sfColor)
    {0, 0, 0, 200});
}
