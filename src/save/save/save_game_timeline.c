/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save_game_timeline
*/

#include "rpg.h"

void save_game_timeline(rpg_t *rpg)
{
    parsed_data_t *data = jp_parse(rpg->save->path);
    parsed_data_t *game = jp_search(data, "game_timeline")->value.p_obj;

    printf("Saving game timeline %i\n", rpg->player->soda);
    jp_search(game, "soda")->value.p_int = rpg->player->soda;
}
