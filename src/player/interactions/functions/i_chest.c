/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** i_chest
*/

#include "rpg.h"

void i_chest(rpg_t *rpg)
{
    (void)(rpg);
    text_t *text = malloc(sizeof(text_t));
    text->id = 888888;
    text->pos = (sfVector2f){rpg->player->pos.x + 30, rpg->player->pos.y - 20};
    text->font = sfFont_createFromFile("resources/fonts/Minecraft.ttf");
    text->scale = (sfVector2f){0.08, 0.08};
    text->color = sfWhite;
    text->string = "Press E to open the chest";
    text->size = 100;
    gl_create_text(rpg->glib, text);
    gl_draw_text(rpg->glib, text->id);
    gl_delete_text(rpg->glib, text->id);
    free(text);

    // if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
    //     printf("Chest opened\n");
}
