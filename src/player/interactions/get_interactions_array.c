/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** get_interactions_array
*/

#include "rpg.h"

interactions_t *get_interactions_array(void)
{
    interactions_t inte_array[] = {
        { "i_house_door", i_house_door }, { "i_house_paper", i_house_paper },
        { "Annia", little_girl }, { "i_house_basement", i_house_basement },
        { "i_grocery_door", i_grocery_door }, { "i_pass_fence", i_pass_fence },
        { "i_end_map_top", i_end_map_top }, { "i_paper_music", i_paper_music },
        { "i_paper_resources", i_paper_resources },
        { "i_basement_paper", i_basement_paper },
        { "i_house1_door", i_house1_door }, {"i_end_map_down", i_end_map_down },
        { NULL, NULL }
    };
    interactions_t *inte = malloc(sizeof(interactions_t) *
        (sizeof(inte_array) / sizeof(interactions_t)));
    for (long unsigned int x = 0; x < sizeof(inte_array) /
        sizeof(interactions_t); x++) {
        inte[x].name = inte_array[x].name;
        inte[x].func = inte_array[x].func;
    }
    return inte;
}
