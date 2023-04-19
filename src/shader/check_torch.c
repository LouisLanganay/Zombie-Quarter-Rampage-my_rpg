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
        sfShader_setVec2Uniform(rpg->shader->shader_torch,
        "resolution", (sfVector2f) {1960 - 1920 * (sfView_getCenter(rpg->player->view->view).x - rpg->player->pos.x ) / sfView_getCenter(rpg->player->view->view).x, 1150 + 1080 * (sfView_getCenter(rpg->player->view->view).y - rpg->player->pos.y ) / sfView_getCenter(rpg->player->view->view).y});
    }
    if (BOTK)
        torch_mouse(960, 1080);
    if (LEFTK)
        torch_mouse(0, 540);
    if (RIGHTK)
        torch_mouse(1920, 540);
    if (TOPLEFTK)
        torch_mouse(0, 0);
    if (TOPRIGHTK)
        torch_mouse(1920, 0);
    if (BOTLEFTK)
        torch_mouse(0, 1080);
    if (BOTRIGHTK)
        torch_mouse(1920, 1080);
}
