/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_popup_lore
*/

#include "rpg.h"

void init_popup_lore(rpg_t *rpg)
{
    sfImage *image = sfImage_createFromFile(PLAYER_GUI_PATH);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    RPA->lore_box = sfSprite_create();
    rpg->player->lore_text = NULL;

    sfSprite_setTexture(RPA->lore_box, texture, sfTrue);
    sfSprite_setTextureRect(RPA->lore_box,
        (sfIntRect){351, 80, 49, 48});
    sfSprite_setScale(RPA->lore_box, (sfVector2f){5, 5});
    sfSprite_setOrigin(RPA->lore_box, (sfVector2f){49 / 2, 48 / 2});
}
