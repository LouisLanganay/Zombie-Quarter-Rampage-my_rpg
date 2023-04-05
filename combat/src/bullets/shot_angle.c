/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** shot_angle
*/

#include "../../includes/rpg.h"
#include <math.h>
#define M_PI 3.14159265358979323846

float shot_angle(sfVector2f pos, sfVector2i mouse)
{
    float angle = atan2(mouse.y - pos.y, mouse.x - pos.x) * 180 / M_PI;
    return angle;
}
