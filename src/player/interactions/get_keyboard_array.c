/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_keyboard_array
*/

#include "rpg.h"

keyboard_images_t *get_keyboard_array(void)
{
    keyboard_images_t keyboard_images[] = {
        { sfKeyUp, 0}, { sfKeyDown, 1}, { sfKeyLeft, 2}, { sfKeyRight, 3},
        { sfKeyF1, 4}, { sfKeyF2, 5}, { sfKeyF3, 6}, { sfKeyF4, 7},
        { sfKeyF5, 8}, { sfKeyF6, 9}, { sfKeyF7, 10}, { sfKeyF8, 11},
        { sfKeyF9, 12}, { sfKeyF10, 13}, { sfKeyF11, 14}, { sfKeyF12, 15},
        { sfKeyA, 16}, { sfKeyB, 17}, { sfKeyC, 18}, { sfKeyD, 19},
        { sfKeyE, 20}, { sfKeyF, 21}, { sfKeyG, 22}, { sfKeyH, 23},
        { sfKeyI, 24}, { sfKeyJ, 25}, { sfKeyK, 26}, { sfKeyL, 27},
        { sfKeyM, 28}, { sfKeyN, 29}, { sfKeyO, 30}, { sfKeyP, 31},
        { sfKeyQ, 32}, { sfKeyR, 33}, { sfKeyS, 34}, { sfKeyT, 35},
        { sfKeyU, 36}, { sfKeyV, 37}, { sfKeyW, 38}, { sfKeyX, 39},
        { sfKeyY, 40}, { sfKeyZ, 41}, { sfKeyUnknown, -1 }
    };
    keyboard_images_t *keyboard = malloc(sizeof(keyboard_images_t) *
        (sizeof(keyboard_images) / sizeof(keyboard_images_t)));
    for (long unsigned int x = 0; x < sizeof(keyboard_images) /
        sizeof(keyboard_images_t); x++) {
        keyboard[x].id = keyboard_images[x].id;
        keyboard[x].key = keyboard_images[x].key;
    }
    return keyboard;
}
