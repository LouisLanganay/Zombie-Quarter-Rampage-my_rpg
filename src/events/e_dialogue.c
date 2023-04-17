/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** e_dialogue
*/

#include "rpg.h"

void e_dialogue(window_t *window, void *main)
{
    (void)(window);
    rpg_t *rpg = (rpg_t *)main;
    time_t time = sfClock_getElapsedTime(rpg->actual_clock).microseconds;
    float seconds = time / 1000000.0;

    if (rpg->player->in_dialogue != 1) return;
    if (DIALOGUE_CHOICE_TIMEOUT) return;
    if (sfKeyboard_isKeyPressed(rpg->player->keys->choice_one.key) == sfTrue
        && rpg->actual_dialog->options != NULL)
        next_dialogue(rpg, 0);
    if (sfKeyboard_isKeyPressed(rpg->player->keys->choice_two.key) == sfTrue
        && rpg->actual_dialog->options != NULL)
        next_dialogue(rpg, 1);
    if (sfKeyboard_isKeyPressed(rpg->player->keys->escape.key) == sfTrue
        && rpg->actual_dialog->options == NULL)
        next_dialogue(rpg, 2);

}
