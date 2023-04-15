/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** number_zombies
*/

#include "rpg.h"

int number_zombies(zombies_t *zombies)
{
    int i = 0;

    for (zombies_t *tmp = zombies; tmp != NULL; tmp = tmp->next)
        i++;
    return (i);
}
