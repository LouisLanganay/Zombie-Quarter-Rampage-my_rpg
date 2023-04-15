/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_settings
*/

#include "rpg.h"

static void update_slider(rpg_t *rpg)
{
    sfVector2i posM = sfMouse_getPositionRenderWindow(
        rpg->glib->window->window);
    if (posM.x > rpg->glib->window->mode.width / 2.4 &&
        posM.x < rpg->glib->window->mode.width / 2.4 + 300
        && posM.y > 400 - 10 && posM.y < 415 + 10) {
        if (sfMouse_isButtonPressed(sfMouseLeft) != 1){
            return;
        }
        rpg->settings->volume = (posM.x - rpg->glib->window->mode.width / 2.4) *
            100 / 300;
        if (rpg->settings->volume >= 100)
            rpg->settings->volume = 100;
        if (rpg->settings->volume <= 0)
            rpg->settings->volume = 0;
    }
}

void draw_settings(rpg_t *rpg)
{
    update_slider(rpg);
    int c_pos = rpg->glib->window->mode.width / 2.4 +
        (rpg->settings->volume * 300 / 100) - 10;
    sfRenderWindow_drawRectangleShape(rpg->glib->window->window,
        rpg->menu->slider_back, NULL);

    sfSprite_setTexture(rpg->menu->slider_sprite,
        rpg->menu->slider_texture, sfTrue);
    sfSprite_setScale(rpg->menu->slider_sprite, (sfVector2f){0.3, 0.3});
    sfSprite_setPosition(rpg->menu->slider_sprite, (sfVector2f){c_pos, 400});
    sfRenderWindow_drawSprite(rpg->glib->window->window,
        rpg->menu->slider_sprite, NULL);
    gl_draw_text(rpg->glib, SETTINGS_VOLUME_TEXT);
}
