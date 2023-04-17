/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** get_interactions_array
*/

#include "rpg.h"

static const interactions_t inte_array[] =
{
    {"i_house_door", i_house_door, NULL},
    {"i_house_paper", i_house_paper,NULL},
    {"Annia", little_girl, NULL},
    {"i_house_basement", i_house_basement, NULL},
    {"i_grocery_door", i_grocery_door, NULL},
    {"i_pass_fence", i_pass_fence, NULL},
    {"i_end_map_top", i_end_map_top, NULL},
    {"i_paper_music", i_paper_music, NULL},
    {"i_paper_resources", i_paper_resources, NULL},
    {"i_basement_paper", i_basement_paper, NULL},
    {"i_soda", i_soda, NULL},
    {"i_house1_door", i_house1_door, NULL},
    {"i_end_map_down", i_end_map_down, NULL},
    {"i_paper_grocery", i_paper_grocery, NULL},
    {"s_nature", s_nature, s_nature_exit},
    {"s_basement", s_basement, s_basement_exit},
    {"s_grocery", s_grocery, s_grocery_exit},
    {"s_radiation", s_radiation, s_radiation_exit},
    {"Jack", jack, NULL },
    {"Guillaume", jack_friend},
    {"i_lauch_combat", i_lauch_combat, NULL},
    {NULL, NULL, NULL}
};

interactions_t *get_interactions_array(void)
{
    interactions_t *inte = malloc(sizeof(interactions_t) *
        (sizeof(inte_array) / sizeof(interactions_t)));
    for (long unsigned int x = 0; x < sizeof(inte_array) /
        sizeof(interactions_t); x++) {
        inte[x].name = inte_array[x].name;
        inte[x].func = inte_array[x].func;
        inte[x].on_exit = inte_array[x].on_exit;
    }
    return inte;
}
