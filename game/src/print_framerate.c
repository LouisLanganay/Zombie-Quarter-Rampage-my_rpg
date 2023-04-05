/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** print_framerate
*/

#include "rpg.h"

void print_framerate(void)
{
    static int first = 1;
    static sfClock *clock;
    static int fps = 0;
    if (first == 1) {
        clock = sfClock_create();
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime(clock);
    if (sfTime_asSeconds(elapsed) >= 1) {
        printf("%3d FPS\r", fps);
        fflush(stdout);
        fps = 0;
        sfClock_restart(clock);
    } else {
        fps ++;
    }
}
