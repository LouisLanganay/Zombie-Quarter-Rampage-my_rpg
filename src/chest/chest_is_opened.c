/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** chest_is_opened
*/

#include "rpg.h"

int chest_is_opened(rpg_t *rpg, char *chest_name)
{
    for (int i = 0; rpg->chests_opened[i] != NULL; i++) {
        if (my_strcmp(chest_name, rpg->chests_opened[i]) == 0)
            return 1;
    }
    return 0;
}
