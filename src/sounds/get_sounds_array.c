/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** get_sounds_array
*/

#include "rpg.h"

sounds_arr_t *get_sounds_array(void)
{
    sounds_arr_t inte_array[] = {
        { "s_basement", s_basement },
        { "s_house", s_house },
        { NULL, NULL }
    };
    sounds_arr_t *inte = malloc(sizeof(sounds_arr_t) *
        (sizeof(inte_array) / sizeof(sounds_arr_t)));
    for (long unsigned int x = 0; x < sizeof(inte_array) /
        sizeof(sounds_arr_t); x++) {
        inte[x].name = inte_array[x].name;
        inte[x].func = inte_array[x].func;
    }
    return inte;
}
