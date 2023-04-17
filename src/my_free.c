/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** my_free
*/

#include "rpg.h"

void my_free(rpg_t *rpg)
{
    sfRenderWindow_destroy(rpg->glib->window->window);
    sfSprite_destroy(rpg->player->assets->lore_box);
}
