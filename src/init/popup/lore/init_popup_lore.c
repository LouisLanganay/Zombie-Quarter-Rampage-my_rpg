/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_popup_lore
*/

#include "rpg.h"

static void init_popup_lore_narative(rpg_t *rpg)
{
    rpg->narative->text = sfText_create();
    rpg->narative->str = NULL;
    rpg->narative->clock = sfClock_create();

    sfText_setString(rpg->narative->text, rpg->narative->str);
    sfText_setFont(rpg->narative->text, gl_get_font(rpg->glib, MINECRAFT_FONT));
    sfText_setCharacterSize(rpg->narative->text, 60);
    sfText_setColor(rpg->narative->text, sfWhite);
    sfText_setScale(rpg->narative->text, (sfVector2f){0.1, 0.1});
}

void init_popup_lore(rpg_t *rpg)
{
    sfImage *image = sfImage_createFromFile(PLAYER_GUI_PATH);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    RPA->lore_box = sfSprite_create();
    rpg->player->lore_text = NULL;
    rpg->narative = malloc(sizeof(narative_t));
    init_popup_lore_narative(rpg);

    sfSprite_setTexture(RPA->lore_box, texture, sfTrue);
    sfSprite_setTextureRect(RPA->lore_box,
        (sfIntRect){351, 80, 49, 48});
    sfSprite_setScale(RPA->lore_box, (sfVector2f){6, 6});
    sfSprite_setOrigin(RPA->lore_box, (sfVector2f){49 / 2, 48 / 2});
}
