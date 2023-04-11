/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_house_door
*/

#include "rpg.h"

static void change_map(rpg_t *rpg)
{
    char *grocery_store = "resources/maps/grocery_store.json";
    char *main_map = "resources/maps/main_map.json";

    if (my_strcmp(rpg->actual_map, grocery_store) == 0) {
        rpg->actual_map = main_map;
        rpg->player->pos.x = SPAWN_OUT_GROCERY_X;
        rpg->player->pos.y = SPAWN_OUT_GROCERY_Y;
    } else if (my_strcmp(rpg->actual_map, main_map) == 0) {
        rpg->actual_map = grocery_store;
        rpg->player->pos.x = SPAWN_IN_GROCERY_X;
        rpg->player->pos.y = SPAWN_IN_GROCERY_Y;
    }
}

void i_grocery_door(rpg_t *rpg, sfVector2f pos)
{
    char *str = NULL;
    if (my_strcmp(rpg->actual_map, "resources/maps/grocery_store.json") == 0) {
        str = get_language(rpg, "grocery_door_interact_leave", RSG);
        draw_interaction_popup(rpg, (sfVector2f){pos.x - 130, pos.y - 10},
            RPK->interact.key, str);
    } else if (my_strcmp(rpg->actual_map,"resources/maps/main_map.json") == 0) {
        str = get_language(rpg, "grocery_door_interact_enter", RSG);
        draw_interaction_popup(rpg, (sfVector2f){pos.x - 150, pos.y - 20},
            RPK->interact.key, str);
    }
    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue)
        change_map(rpg);
    while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
}
