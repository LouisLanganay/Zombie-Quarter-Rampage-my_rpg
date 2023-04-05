/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "../../combat/includes/rpg.h"
#include "math.h"
#define M_PI 3.14159265358979323846

//1 = Background
//2 = Player

void event_window_close(window_t *window)
{
    sfRenderWindow_close(window->window);
}



void init_background(rpg_t *rpg)
{
    sprite_t *my_sprite = malloc(sizeof(sprite_t));
    my_sprite->id = 1;
    my_sprite->pos = (sfVector2f){0, 0};
    my_sprite->sprite = sfSprite_create();
    my_sprite->texture = sfTexture_createFromFile("assets/map_night.jpg", NULL);
    my_sprite->scale = (sfVector2f){1.25, 1.35};
    my_sprite->call_action = NULL;
    gl_create_sprite(rpg->glib, my_sprite);
}

void init_guy(rpg_t *rpg)
{
    sprite_t *my_sprite = malloc(sizeof(sprite_t));
    my_sprite->id = 2;
    my_sprite->pos = (sfVector2f){0, 500};
    my_sprite->sprite = sfSprite_create();
    my_sprite->texture = sfTexture_createFromFile("assets/guy.png", NULL);
    my_sprite->scale = (sfVector2f){1.25, 1.35};
    my_sprite->call_action = NULL;
    gl_create_sprite(rpg->glib, my_sprite);
}

void move_player(rpg_t *rpg, sfClock *clock)
{
    float time = sfClock_getElapsedTime(clock).microseconds;
    float seconds = time / 1000000.0;
    sfVector2f sprite_pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 2));
    if (seconds > 0.0075) {
        if (sfKeyboard_isKeyPressed(sfKeyZ) && sprite_pos.y > 200)
            sfSprite_move(gl_get_sprite(rpg->glib, 2), (sfVector2f){0, -5});
        if (sfKeyboard_isKeyPressed(sfKeyS) && sprite_pos.y < 620)
            sfSprite_move(gl_get_sprite(rpg->glib, 2), (sfVector2f){0, 5});
        if (sfKeyboard_isKeyPressed(sfKeyQ) && sprite_pos.x > 10)
            sfSprite_move(gl_get_sprite(rpg->glib, 2), (sfVector2f){-5, 0});
        if (sfKeyboard_isKeyPressed(sfKeyD) && sprite_pos.x < 1850)
            sfSprite_move(gl_get_sprite(rpg->glib, 2), (sfVector2f){5, 0});
        sfClock_restart(clock);
    }
}

void init_boss(rpg_t *rpg)
{
    sprite_t *my_sprite = malloc(sizeof(sprite_t));
    my_sprite->id = 0;
    my_sprite->pos = (sfVector2f){1900, 300};
    my_sprite->sprite = sfSprite_create();
    my_sprite->texture = sfTexture_createFromFile("assets/boss.png", NULL);
    my_sprite->scale = (sfVector2f){-3.0, 3.0};
    my_sprite->call_action = NULL;
    gl_create_sprite(rpg->glib, my_sprite);
}

int main(int ac, char **av)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    init_rpg(rpg, ac, av);
    init(rpg);
    init_background(rpg);
    init_guy(rpg);
    init_boss(rpg);
    gl_create_event(rpg->glib, 50, sfEvtClosed, e_close);
    sfClock *clock = sfClock_create();
    sfClock *clock_shoot = sfClock_create();
    bullets_t *bullets = NULL;
    zombies_t *zombies = NULL;
    sfClock *clock_zombies = sfClock_create();


    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        print_framerate();
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        gl_draw_sprite(rpg->glib, 1);
        gl_draw_sprite(rpg->glib, 0);
        move_player(rpg, clock);
        if (sfMouse_isButtonPressed(sfMouseLeft) && sfClock_getElapsedTime(clock_shoot).microseconds / 200000.0 > 1) {
            insert_bullet(&bullets, rpg);
            print_len_bullets(bullets);
            sfClock_restart(clock_shoot);
        }
        draw_bullets(bullets, rpg);
        gl_draw_sprite(rpg->glib, 2);
        move_bullets(bullets);
        if (sfMouse_isButtonPressed(sfMouseRight)) {
            sfClock_restart(clock);
        }
        if (zombies == NULL)
            insert_zombies(rpg, &zombies);
        move_zombies(zombies, rpg);
        //delete_zombie(zombies, zombies->next);
        //insert_zombies(rpg, &zombies);
        //move_zombies(zombies, rpg);
        draw_zombies(zombies, rpg);
        //move_zombies(zombies, rpg);
        //bullet_hit_zombies(zombies, bullets);
        colision_bullet_zombies(zombies, bullets);
        if (sfClock_getElapsedTime(clock_zombies).microseconds / 2000000.0 > 1) {
            move_zombies(zombies, rpg);
            sfClock_restart(clock_zombies);
        }
        delete_outmap_bullet(&bullets);
        gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
        sfRenderWindow_display(rpg->glib->window->window);
    }
}
