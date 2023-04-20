/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** wave
*/

#include "rpg.h"

static void if_zombie(char **wave,
zombies_t **zombies, sfVector2f pos)
{
    int i = pos.x;
    int j = pos.y;
    if (wave[i][j] == 'z') {
        insert_zombies_coord(zombies, (sfVector2f) {(i + 1)
        * 1920 + rand() % 500, 620 - j * 52});
    }
}

void wave(char **wave, zombies_t **zombies)
{
    for (int i = 0; wave[i] != NULL; i++) {
        for (int j = 0; wave[i][j] != '\0'; j++) {
            if_zombie(wave, zombies, (sfVector2f) {i, j});
        }
    }
}
