/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_quests_func_arr
*/

#include "rpg.h"


quests_func_t *get_quests_func_arr(void)
{
    quests_func_t quests_func[] = {
        { "go_to_annia", go_to_annia },
        { NULL, NULL}
    };
    quests_func_t *arr = malloc(sizeof(quests_func_t) *
        (sizeof(quests_func) / sizeof(quests_func_t)));
    for (long unsigned int x = 0; x < sizeof(quests_func) /
        sizeof(quests_func_t); x++) {
        arr[x].name = quests_func[x].name;
        arr[x].func = quests_func[x].func;
    }
    return arr;
}
