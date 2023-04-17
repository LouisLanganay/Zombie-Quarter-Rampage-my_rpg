/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** combat
*/

#include "rpg.h"

static void fill_combat_rpg(rpg_t *rpg)
{
    init_guy(rpg);
    init_background(rpg);
    gl_create_event(rpg->glib, 50, sfEvtClosed, e_close);
    rpg->player->pos = (sfVector2f){50, 600};
    sfSprite_setScale(rpg->player->sprite, (sfVector2f) {3.5, 3.5});
    rpg->player->hp_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(rpg->player->hp_bar,
    (sfVector2f){rpg->player->hp, 10});
    sfRectangleShape_setPosition(rpg->player->hp_bar,
    (sfVector2f){rpg->player->pos.x - 72 - rpg->player->hp
    / 2, rpg->player->pos.y + 20});
    sfRectangleShape_setFillColor(rpg->player->hp_bar, sfGreen);
}

static void window_manager(rpg_t *rpg)
{
    print_framerate();
    sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
    gl_draw_sprite(rpg->glib, 1);
    gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
}

static void combat_manager(rpg_t *rpg, combat_t *combat)
{
        animation_zombie(combat->zombies);
        delete_zombie_status(&combat->zombies);
        move_player(rpg, combat->clock_move);
        move_zombies(combat->zombies, rpg);
        colision_bullet_zombies(combat->zombies, combat->bullets);
        delete_bullet_status(&combat->bullets);
        draw_zombies(combat->zombies, rpg);
        gun_manager(rpg, combat);
        cbt_draw_player(rpg);
}

int combat(rpg_t *rpg)
{
    srand(time(NULL));
    sfVector2f old_pos = rpg->player->pos;
    fill_combat_rpg(rpg);
    combat_t *combat = init_combat();
    wave(wave_zombie1(), rpg, &combat->zombies);
    rpg->game_state = COMBAT;

    while (condition_window) {
        window_manager(rpg);
        combat_manager(rpg, combat);
        check_shader(rpg);
        sfRenderWindow_display(rpg->glib->window->window);
        if (rpg->game_state == MENU)
            return (0);
    }
    sfSprite_setScale(rpg->player->sprite, (sfVector2f) {1, 1});
    rpg->player->pos = old_pos;
}
