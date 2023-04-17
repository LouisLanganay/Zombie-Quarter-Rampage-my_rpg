/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** e_save_btn
*/

#include "rpg.h"

void e_save_btn(int id, void *main)
{
    (void)id;
    rpg_t *rpg = (rpg_t *)main;
    save(rpg);
}
