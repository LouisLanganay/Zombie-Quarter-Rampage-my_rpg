/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** print_len_bullets
*/

#include "../../includes/rpg.h"

void print_len_bullets(bullets_t *bullets)
{
    int i = 0;
    bullets_t *tmp = bullets;
    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    printf("len = %d\n", i);
}