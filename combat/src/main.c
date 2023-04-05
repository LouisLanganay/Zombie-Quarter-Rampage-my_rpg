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

sfSprite *gl_get_sprite(GLib_t *glib, int id)
{
    sprite_t *tmp = glib->sprites;
    while (tmp != NULL) {
        if (tmp->id == id) {
            return tmp->sprite;
        }
        tmp = tmp->next;
    }
    return NULL;
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

float shot_angle(sfVector2f pos, sfVector2i mouse)
{
    float angle = atan2(mouse.y - pos.y, mouse.x - pos.x) * 180 / M_PI;
    return angle;
}

void insert_bullet(bullets_t **list, rpg_t *rpg)
{
    bullets_t *new_node = malloc(sizeof(bullets_t));
    new_node->speed = 10;
    new_node->pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 2));
    new_node->sprite = sfSprite_create();
    new_node->texture = sfTexture_createFromFile("assets/bullet.png", NULL);
    new_node->rect = (sfIntRect){0, 0, 100, 100};
    new_node->scale = (sfVector2f){1.0, 1.0};
    new_node->angle = shot_angle(new_node->pos, sfMouse_getPositionRenderWindow(rpg->glib->window->window));
    new_node->next = *list;
    sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
    sfSprite_setTextureRect(new_node->sprite, new_node->rect);
    sfSprite_setScale(new_node->sprite, new_node->scale);
    sfSprite_setPosition(new_node->sprite, new_node->pos);
    *list = new_node;
}

void delete_bullet(bullets_t **list, int index)
{
    bullets_t *tmp = *list;
    bullets_t *prev = NULL;
    int i = 0;
    if (tmp == NULL)
        return;
    if (index == 0) {
        *list = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && i != index) {
        prev = tmp;
        tmp = tmp->next;
        i++;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
}

void move_bullets(bullets_t *bullets)
{
    bullets_t *tmp = bullets;
    while (tmp != NULL) {
        tmp->pos.x += cos(tmp->angle * M_PI / 180) * tmp->speed;
        tmp->pos.y += sin(tmp->angle * M_PI / 180) * tmp->speed;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        tmp = tmp->next;
    }
}

void delete_outmap_bullet(bullets_t **bullets)
{
    bullets_t *tmp = *bullets;
    if (tmp == NULL)
        return;
    int i = 0;
    while (tmp != NULL) {
        if (tmp->pos.x > 1920 || tmp->pos.x < 0 || tmp->pos.y > 1080 || tmp->pos.y < 0) {
            delete_bullet(bullets, i);
            return;
        }
        tmp = tmp->next;
        i++;
    }
}

void print_len_list(bullets_t *bullets)
{
    int i = 0;
    bullets_t *tmp = bullets;
    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    printf("len = %d\n", i);
}

void delete_element(bullets_t *bullets, int index)
{
    bullets_t *tmp = bullets;
    int i = 0;
    while (tmp->next != NULL) {
        if (i == index) {
            tmp->next = tmp->next->next;
            return;
        }
        i++;
        tmp = tmp->next;
    }
}

void draw_bullets(bullets_t *bullets, rpg_t *rpg)
{
    bullets_t *tmp = bullets;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(rpg->glib->window->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void hit_by_bullet(sfSprite *sprite, bullets_t *bullets)
{
    sfVector2f sprite_pos = sfSprite_getPosition(sprite);
    sfVector2f sprite_size = sfSprite_getScale(sprite);
    bullets_t *tmp = bullets;
    while (tmp != NULL) {
        if (tmp->pos.x > sprite_pos.x && tmp->pos.x < sprite_pos.x + sprite_size.x * 100) {
            if (tmp->pos.y > sprite_pos.y && tmp->pos.y < sprite_pos.y + sprite_size.y * 100) {
                printf("hit");
            }
        }
        tmp = tmp->next;
    }
}

void collision(sfRectangleShape *hitbox, bullets_t *bullets)
{
    bullets_t *tmp = bullets;
    int i = 0;
    while (tmp != NULL) {
        if (colision_with_rect(hitbox, tmp->pos) == 1) {
            delete_element(bullets, i);
            printf(":::hit\n");
        }
        tmp = tmp->next;
        i++;
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

void insert_zombies(rpg_t *rpg, zombies_t **list)
{
    zombies_t *new_node = malloc(sizeof(zombies_t));
    //new_node->pos = (sfVector2f){1920 + rand() % 1000, rand() % 1080};
    new_node->pos = (sfVector2f){1920 / 2, 1080 / 2};
    new_node->type = 1;
    new_node->hp = 100;
    new_node->damage = 10;
    new_node->speed = 1;

    new_node->hitbox = sfRectangleShape_create();
    sfRectangleShape_setPosition(new_node->hitbox, new_node->pos);
    sfRectangleShape_setSize(new_node->hitbox, (sfVector2f){60, 100});
    sfRectangleShape_setFillColor(new_node->hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(new_node->hitbox, sfRed);
    sfRectangleShape_setOutlineThickness(new_node->hitbox, 3);
    // sfRectangleShape_setOrigin(new_node->hitbox, (sfVector2f){new_node->pos.x + 50, new_node->pos.y + 50});
    //sfRectangleShape_setRotation(new_node->hitbox, 0);
    sfRectangleShape_setScale(new_node->hitbox, (sfVector2f){-1, 1});
    sfRectangleShape_move(new_node->hitbox, (sfVector2f){-60, 40});
    new_node->sprite = sfSprite_create();
    new_node->texture = sfTexture_createFromFile("assets/zombie.png", NULL);
    new_node->rect = (sfIntRect){0, 0, 72, 72};
    new_node->scale = (sfVector2f){-2.0, 2.0};
    sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
    sfSprite_setTextureRect(new_node->sprite, new_node->rect);
    sfSprite_setPosition(new_node->sprite, new_node->pos);
    sfSprite_setScale(new_node->sprite, new_node->scale);
    new_node->next = *list;
    *list = new_node;
}

void move_zombies(zombies_t *list, rpg_t *rpg)
{
    zombies_t *tmp = list;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        tmp->pos.x -= tmp->speed;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfRectangleShape_setPosition(tmp->hitbox, sfSprite_getPosition(tmp->sprite));
        tmp = tmp->next;
    }
}

void draw_zombies(zombies_t *list, rpg_t *rpg)
{
    zombies_t *tmp = list;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(rpg->glib->window->window, tmp->sprite, NULL);
        sfRenderWindow_drawRectangleShape(rpg->glib->window->window, tmp->hitbox, NULL);
        tmp = tmp->next;
    }
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

    // sfRectangleShape *rect = sfRectangleShape_create();
    // sfRectangleShape_setPosition(rect, (sfVector2f){1500, 300});
    // sfRectangleShape_setSize(rect, (sfVector2f){100, 100});
    // sfRectangleShape_setFillColor(rect, sfTransparent);
    // sfRectangleShape_setOutlineColor(rect, sfRed);
    // sfRectangleShape_setOutlineThickness(rect, 5);
    // sfRectangleShape_setScale(rect, (sfVector2f){-3.0, 3.0});



    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        print_framerate();
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        gl_draw_sprite(rpg->glib, 1);
        gl_draw_sprite(rpg->glib, 0);
        move_player(rpg, clock);
        if (sfMouse_isButtonPressed(sfMouseLeft) && sfClock_getElapsedTime(clock_shoot).microseconds / 200000.0 > 1) {
            //bullet_insert(bullets, rpg);
            insert_bullet(&bullets, rpg);
            print_len_list(bullets);
            sfClock_restart(clock_shoot);
        }
        draw_bullets(bullets, rpg);
        gl_draw_sprite(rpg->glib, 2);
        move_bullets(bullets);
        if (sfMouse_isButtonPressed(sfMouseRight)) {
            sfClock_restart(clock);
        }
        if (zombies == NULL) {
            insert_zombies(rpg, &zombies);
            printf("zombie inserted\n");
        }
        //insert_zombies(rpg, &zombies);
        //move_zombies(zombies, rpg);
        draw_zombies(zombies, rpg);
        //if (sfMouse_isButtonPressed(sfMouseLeft)) {
        //    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->glib->window->window);
        //    sfVector2f mouse_pos_f = (sfVector2f){mouse_pos.x, mouse_pos.y};
        //    //click_in_rect(rect, mouse_pos_f);
        //}
        //bullets = delete_outmap_bullet(bullets);
        //hit_boss(rpg, bullets);
        // sfRenderWindow_drawRectangleShape(rpg->glib->window->window, rect, NULL);
        //collision(rect, bullets);
        //hit_by_bullet(gl_get_sprite(rpg->glib, 0), bullets);
        //print_len_list(bullets);
        delete_outmap_bullet(&bullets);
        gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
        sfRenderWindow_display(rpg->glib->window->window);
    }
}
