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

void animation_zombie(zombies_t *list)
{
    zombies_t *tmp = list;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        tmp->animation++;
        if (tmp->animation == 8)
            tmp->animation = 0;
        if (tmp->animation == 0)
            sfSprite_setTexture (tmp->sprite, sfTexture_createFromFile("assets/zombie_0.png", NULL), sfTrue);
        if (tmp->animation == 1)
            sfSprite_setTexture (tmp->sprite, sfTexture_createFromFile("assets/zombie_1.png", NULL), sfTrue);
        if (tmp->animation == 2)
            sfSprite_setTexture (tmp->sprite, sfTexture_createFromFile("assets/zombie_2.png", NULL), sfTrue);
        if (tmp->animation == 3)
            sfSprite_setTexture (tmp->sprite, sfTexture_createFromFile("assets/zombie_3.png", NULL), sfTrue);
        if (tmp->animation == 4)
            sfSprite_setTexture (tmp->sprite, sfTexture_createFromFile("assets/zombie_4.png", NULL), sfTrue);
        if (tmp->animation == 5)
            sfSprite_setTexture (tmp->sprite, sfTexture_createFromFile("assets/zombie_5.png", NULL), sfTrue);
        if (tmp->animation == 6)
            sfSprite_setTexture (tmp->sprite, sfTexture_createFromFile("assets/zombie_6.png", NULL), sfTrue);
        if (tmp->animation == 7)
            sfSprite_setTexture (tmp->sprite, sfTexture_createFromFile("assets/zombie_7.png", NULL), sfTrue);
        tmp = tmp->next;
    }
}

void use_gun(rpg_t *rpg, sfClock *clock_shoot, bullets_t **bullets)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    sfClock_getElapsedTime(clock_shoot).microseconds / 200000.0 > 1) {
        insert_bullet(bullets, rpg);
        sfClock_restart(clock_shoot);
    }
}

void wave(rpg_t *rpg, sfClock *clock_wave, zombies_t **zombies)
{
    float seconds = sfClock_getElapsedTime(clock_wave).microseconds / 1000000.0;

    if (seconds > 10) {
        int nb_zombies = rand() % 5;
        for (int i = 0; i < nb_zombies; i++) {
            insert_zombies(rpg, zombies);
        }
        sfClock_restart(clock_wave);
    }

}

void printf_len_zombies(zombies_t *list)
{
    zombies_t *tmp = list;
    int i = 0;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    printf("Zombies: %d\n", i);
}

int distance(sfVector2f pos1, sfVector2f pos2)
{
    return (sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2)));
}

int main(int ac, char **av)
{
    srand(time(NULL));
    rpg_t *rpg = malloc(sizeof(rpg_t));
    init_rpg(rpg, ac, av);
    init(rpg);
    init_background(rpg);
    init_guy(rpg);
    gl_create_event(rpg->glib, 50, sfEvtClosed, e_close);
    sfClock *clock = sfClock_create();
    sfClock *clock_shoot = sfClock_create();
    bullets_t *bullets = NULL;
    zombies_t *zombies = NULL;
    sfClock *clock_zombies = sfClock_create();
    sfClock *clock_animation = sfClock_create();
    sfClock *clock_wave = sfClock_create();
    sfClock *attack_speed = sfClock_create();
    rpg->player->hp = 100;
    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        wave(rpg, clock_wave, &zombies);
        print_framerate();
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        if (sfMouse_isButtonPressed(sfMouseLeft) && sfClock_getElapsedTime(clock_shoot).microseconds / 200000.0 > 1)
            use_gun(rpg, clock_shoot, &bullets);
        move_player(rpg, clock);
        move_bullets(bullets);
        move_zombies(zombies, rpg, attack_speed);
        colision_bullet_zombies(zombies, bullets);
        delete_zombie_status(&zombies);
        delete_bullet_status(&bullets);
        if (sfClock_getElapsedTime(clock_animation).microseconds / 200000.0 > 1) {
            animation_zombie(zombies);
            sfClock_restart(clock_animation);
        }
        gl_draw_sprite(rpg->glib, 1);
        draw_bullets(bullets, rpg);
        draw_zombies(zombies, rpg);
        gl_draw_sprite(rpg->glib, 2);
        gl_draw_sprite(rpg->glib, 0);
        delete_outmap_bullet(&bullets);
        gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
        sfRenderWindow_display(rpg->glib->window->window);
    }
}
