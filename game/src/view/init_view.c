/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_view
*/

#include "rpg.h"

sfView *init_view(
    sfVector2f screen_size,
    float view_zoom,
    float view_center_div
)
{
    sfView *view = sfView_create();
    sfView_setCenter(view, (sfVector2f)
        {
            screen_size.x / view_center_div, screen_size.y / view_center_div
        }
    );
    sfView_setSize(view, (sfVector2f)
        {
            screen_size.x, screen_size.y
        }
    );
    sfView_zoom(view, view_zoom);
    return view;
}
