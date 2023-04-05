/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_quest_assets
*/

#include "rpg.h"

void init_quest_bg(rpg_t *rpg)
{
    sfImage *image = sfImage_createFromFile(PLAYER_GUI_PATH);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    rpg->player->assets->quests_box = sfSprite_create();

    sfSprite_setTexture(RPA->quests_box, texture, sfTrue);
    sfSprite_setTextureRect(RPA->quests_box,
        (sfIntRect){288, 16, 48, 47});
    sfSprite_setScale(RPA->quests_box, (sfVector2f){2, 2});
    sfSprite_setOrigin(RPA->quests_box, (sfVector2f){48, 0});

}

void init_quest_icons(rpg_t *rpg)
{
    sfImage *image = sfImage_createFromFile(PLAYER_GUI_PATH);
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    rpg->player->assets->quest_icons->go_to = sfSprite_create();
    rpg->player->assets->quest_icons->talk = sfSprite_create();

    sfSprite_setTexture(RPAQ->go_to, texture, sfTrue);
    sfSprite_setTextureRect(RPAQ->go_to, (sfIntRect){976, 305, 16, 16});
    sfSprite_setScale(RPAQ->go_to, (sfVector2f){0.6, 0.6});

    sfSprite_setTexture(RPAQ->talk, texture, sfTrue);
    sfSprite_setTextureRect(RPAQ->talk, (sfIntRect){976, 256, 16, 16});
    sfSprite_setScale(RPAQ->talk, (sfVector2f){0.6, 0.6});
}

void init_quest_assets(rpg_t *rpg)
{
    init_quest_bg(rpg);
    rpg->player->assets->quest_icons = malloc(sizeof(quest_icons_t));
    init_quest_icons(rpg);
}
