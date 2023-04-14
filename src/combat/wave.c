/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** wave
*/

#include "rpg.h"

static void if_zombie(char **wave, rpg_t *rpg,
zombies_t **zombies, sfVector2f pos)
{
    int i = pos.x;
    int j = pos.y;
    if (wave[i][j] == 'z') {
        insert_zombies_coord(rpg, zombies, (sfVector2f) {(i + 1)
        * 1920 + rand() % 500, 620 - j * 52});
    }
}

void wave(char **wave, rpg_t *rpg, zombies_t **zombies)
{
    int i = 0;
    int j = 0;
    for (int i = 0; wave[i] != NULL; i++) {
        for (int j = 0; wave[i][j] != '\0'; j++) {
            if_zombie(wave, rpg, zombies, (sfVector2f) {i, j});
        }
    }
}
