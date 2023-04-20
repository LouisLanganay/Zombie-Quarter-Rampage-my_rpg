/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** draw_layer
*/

#include "rpg.h"

void draw_layer(rpg_t *rpg, layer_t *layer)
{
    sfVector2f center = sfView_getCenter(rpg->player->view->view);
    sfVector2f size = sfView_getSize(rpg->player->view->view);
    sfFloatRect rect = {
        (center.x - size.x / 2) - 16, (center.y - size.y / 2) - 16,
        size.x + 16, size.y + 16
    };
    int x;
    int y;

    if (quest_is_in_progress(rpg, "run_away") == 1)
        if (my_strcmp(layer->name, "military") == 0) return;
    if (quest_is_in_progress(rpg, "run_away") == 0)
        if (my_strcmp(layer->name, "military2") == 0) return;
    for (int i = 0; i < layer->height * layer->width; i++) {
        x = i % layer->width * 16;
        y = i / layer->width * 16;
        if (sfFloatRect_contains(&rect, x, y) == sfTrue)
            sfRenderWindow_drawSprite(rpg->glib->window->window,
                layer->sprites[i], NULL);
    }
}
