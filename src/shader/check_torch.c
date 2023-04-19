/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_torch
*/

#include "rpg.h"

void check_torch(rpg_t *rpg)
{
    if (TOPK) {
        torch_mouse(960, 0);
        torch_resolution1;
    }
    if (BOTK)
        torch_mouse(960, 1080);
    if (LEFTK) {
        torch_mouse(0, 540);
        torch_resolution1;
    }
    if (RIGHTK)
        torch_mouse(1920, 540);
    if (TOPLEFTK) {
        torch_mouse(0, 0);
        torch_resolution1;
    }
    if (TOPRIGHTK)
        torch_mouse(1920, 0);
    if (BOTLEFTK) {
        torch_mouse(0, 1080);
        torch_resolution1;
    }
    if (BOTRIGHTK)
        torch_mouse(1920, 1080);
}
