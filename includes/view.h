/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** view
*/

#ifndef _VIEW_H__
    #define _VIEW_H__

    #include "rpg.h"

    #define MAP_MARGIN_X 290
    #define MAP_MARGIN_Y 165

    sfView *init_view(
        sfVector2f screen_size,
        float view_zoom,
        float view_center_div
    );


#endif
