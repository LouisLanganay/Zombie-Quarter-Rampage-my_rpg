/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_torch
*/

#include "rpg.h"

sfVector2f torch_view(rpg_t *rpg, sfVector2i r, sfVector2f m)
{
    float xr = r.x / 1960.0;
    float yr = r.y / 1150.0;
    m.x = TOPK ? 960 * xr : LEFTK ? 0 : RIGHTK ? 1920 * xr :
    TOPLEFTK || TOPRIGHTK ? 0 : 960 * xr;
    m.y = LEFTK || RIGHTK ? 540 * yr : TOPK ? 0 : BOTK ? 1080
    * yr : TOPLEFTK || BOTLEFTK ? 0 : 1080 * yr;
    if (BOTRIGHTK || TOPRIGHTK)
        m.x = 1920 * xr;
    if (BOTLEFTK || BOTRIGHTK)
        m.y = 1080 * yr;
    return m;
}

void torch_res(rpg_t *rpg)
{
    sfVector2f res;
    sfVector2f m;
    float top = tr;
    float left = lr;
    float bot = br;
    float right = rr;
    float middle_map_x = 1150.0;
    float middle_map_y = 900.0;
    float player_x = rpg->player->pos.x;
    float player_y = rpg->player->pos.y;
    (player_x < middle_map_x) ? (res.x = top) : (res.x = bot);
    (player_y < middle_map_y) ? (res.y = left) : (res.y = right);
    sfVector2i r = (sfVector2i) {(int) res.x, (int) res.y};
    if (r.x != 1960 && r.y != 1150) {
        m = torch_view(rpg, r, m);
        sfShader_setVec2Uniform(rpg->shader->shader_torch, "mouse", m);
    }
    sfShader_setVec2Uniform(rpg->shader->shader_torch, "resolution", res);
}

void check_torch(rpg_t *rpg)
{
    if (TOPK)
        torch_mouse(960, 0);
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
    torch_res(rpg);
}
