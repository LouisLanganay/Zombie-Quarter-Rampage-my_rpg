/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** map_zombies
*/

#include "rpg.h"

char **wave_zombie1(void)
{
    char **wave_zombie = malloc(sizeof(char *) * 10);
    wave_zombie[0] = "z.....zzz";
    wave_zombie[1] = ".........";
    wave_zombie[2] = ".........";
    wave_zombie[3] = ".........";
    wave_zombie[4] = ".........";
    wave_zombie[5] = ".........";
    wave_zombie[6] = ".........";
    wave_zombie[7] = ".........";
    wave_zombie[8] = ".........";
    wave_zombie[9] = NULL;
    return (wave_zombie);
}
