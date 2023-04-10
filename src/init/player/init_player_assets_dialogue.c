/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_player_assets_dialogue
*/

#include "rpg.h"

static void init_player_assets_dialogue_box(player_t *player)
{
    sfImage *image = sfImage_createFromFile(PLAYER_GUI_PATH);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    player->assets->dialog_box = sfSprite_create();

    sfSprite_setTexture(player->assets->dialog_box, texture, sfTrue);
    sfSprite_setTextureRect(player->assets->dialog_box,
        (sfIntRect){350, 64, 50, 15});
    sfSprite_setScale(player->assets->dialog_box, (sfVector2f){5, 5});
    sfSprite_setOrigin(player->assets->dialog_box, (sfVector2f){50 / 2, 0});
}

void init_player_assets_dialogue(player_t *player)
{
    init_player_assets_dialogue_box(player);
}
