/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_house_door
*/

#include "rpg.h"

static void change_map(rpg_t *rpg)
{
    char *player_basement = "resources/maps/player_basement.json";
    char *player_house = "resources/maps/player_house.json";

    if (my_strcmp(rpg->actual_map, player_basement) == 0) {
        rpg->actual_map = player_house;
        rpg->player->pos.x = SPAWN_OUT_BASEMENT_X;
        rpg->player->pos.y = SPAWN_OUT_BASEMENT_Y;
    } else if (my_strcmp(rpg->actual_map, player_house) == 0) {
        rpg->actual_map = player_basement;
        rpg->player->pos.x = SPAWN_IN_BASEMENT_X;
        rpg->player->pos.y = SPAWN_IN_BASEMENT_Y;
    }
}

void i_house_basement(rpg_t *rpg, sfVector2f pos)
{
    char *str = NULL;
    if (my_strcmp(rpg->actual_map, BASEMENT_MAP_PATH) == 0) {
        str = get_language(rpg, "basement_door_interact_leave", RSG);
        draw_interaction_popup(rpg, (sfVector2f){pos.x - 80, pos.y - 25},
            RPK->interact.key, str);
    } else if (my_strcmp(rpg->actual_map, HOUSE_MAP_PATH) == 0) {
        str = get_language(rpg, "basement_door_interact_enter", RSG);
        draw_interaction_popup(rpg, (sfVector2f){pos.x - 20, pos.y - 25},
            RPK->interact.key, str);
    }
    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue)
        change_map(rpg);
    while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
}
