/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_house1_door
*/

#include "rpg.h"

static void change_map(rpg_t *rpg)
{
    char *house1 = "resources/maps/house1.json";
    char *main_map = "resources/maps/main_map.json";

    if (my_strcmp(rpg->actual_map, house1) == 0) {
        rpg->actual_map = main_map;
        rpg->player->pos.x = SPAWN_OUT_HOUSE1_X;
        rpg->player->pos.y = SPAWN_OUT_HOUSE1_Y;
    } else if (my_strcmp(rpg->actual_map, main_map) == 0) {
        rpg->actual_map = house1;
        rpg->player->pos.x = SPAWN_INTO_HOUSE1_X;
        rpg->player->pos.y = SPAWN_INTO_HOUSE1_Y;
    }
}

void i_house1_door(rpg_t *rpg, sfVector2f pos)
{
    char *str = NULL;
    if (my_strcmp(rpg->actual_map, "resources/maps/house1.json") == 0) {
        str = get_language(rpg, "house1_door_interact_leave", RSG);
        draw_interaction_popup(rpg, ((sfVector2f){pos.x - 100, pos.y - 20}),
            RPK->interact.key, str);
    } else if (my_strcmp(rpg->actual_map,"resources/maps/main_map.json") == 0) {
        str = get_language(rpg, "house1_door_interact_enter", RSG);
        draw_interaction_popup(rpg, (pos), RPK->interact.key, str);
    }
    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue)
        change_map(rpg);
    while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
}
