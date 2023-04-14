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
}

static void window_manager(rpg_t *rpg)
{
    print_framerate();
    sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
    gl_draw_sprite(rpg->glib, 1);
    // gl_draw_sprite(rpg->glib, 2);
    gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
}

int combat(rpg_t *rpg)
{
    srand(time(NULL));
    fill_combat_rpg(rpg);
    combat_t *combat = init_combat();
    sfClock *clock = sfClock_create();
    wave(wave_zombie1(), rpg, &combat->zombies);
    sfVector2f old_pos = rpg->player->pos;
    rpg->player->pos = (sfVector2f){50, 600};
    sfSprite_setScale(rpg->player->sprite, (sfVector2f) {3.5, 3.5});
    while (condition_window) {
        window_manager(rpg);
        move_player(rpg, combat->clock_move);
        move_zombies(combat->zombies, rpg);
        colision_bullet_zombies(combat->zombies, combat->bullets);
        delete_zombie_status(&combat->zombies);
        delete_bullet_status(&combat->bullets);
        animation_zombie(combat->zombies);
        draw_zombies(combat->zombies, rpg);
        cbt_draw_player(rpg);
        gun_manager(rpg, combat);
        sfRenderWindow_display(rpg->glib->window->window);
    }
    sfSprite_setScale(rpg->player->sprite, (sfVector2f) {1, 1});
    rpg->player->pos = old_pos;
}
