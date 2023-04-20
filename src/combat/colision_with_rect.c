/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** colision_with_rect
*/

#include "rpg.h"

static int check_colision_1(sfVector2f rect_pos, sfVector2f rect_scale,
sfVector2f pos)
{
    if (pos.x > rect_pos.x && pos.x < rect_pos.x + rect_scale.x * 100) {
        if (pos.y < rect_pos.y && pos.y > rect_pos.y + rect_scale.y * 100) {
            return (1);
        }
    }
    return (0);
}

static int check_colision_2(sfVector2f rect_pos, sfVector2f rect_scale,
sfVector2f pos)
{
    if (pos.x < rect_pos.x && pos.x > rect_pos.x + rect_scale.x * 100) {
        if (pos.y > rect_pos.y && pos.y < rect_pos.y + rect_scale.y * 100) {
            return (1);
        }
    }
    return (0);
}

static int check_colision_3(sfVector2f rect_pos, sfVector2f rect_scale,
sfVector2f pos)
{
    if (pos.x > rect_pos.x && pos.x < rect_pos.x + rect_scale.x * 100) {
        if (pos.y > rect_pos.y && pos.y < rect_pos.y + rect_scale.y * 100) {
            return (1);
        }
    }
    return (0);
}

static int check_colision_4(sfVector2f rect_pos, sfVector2f rect_scale,
sfVector2f pos)
{
    if (pos.x < rect_pos.x && pos.x > rect_pos.x + rect_scale.x * 100) {
        if (pos.y < rect_pos.y && pos.y > rect_pos.y + rect_scale.y * 100) {
            return (1);
        }
    }
    return (0);
}

int colision_with_rect(sfRectangleShape *rect, sfVector2f pos)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);
    sfVector2f rect_scale = sfRectangleShape_getScale(rect);
    if (rect_scale.x > 0 && rect_scale.y < 0)
        return (check_colision_1(rect_pos, rect_scale, pos));
    if (rect_scale.x < 0 && rect_scale.y > 0)
        return (check_colision_2(rect_pos, rect_scale, pos));
    if (rect_scale.x > 0 && rect_scale.y > 0)
        return (check_colision_3(rect_pos, rect_scale, pos));
    if (rect_scale.x < 0 && rect_scale.y < 0)
        return (check_colision_4(rect_pos, rect_scale, pos));
    return (0);
}
