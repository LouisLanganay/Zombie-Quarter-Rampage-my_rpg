/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** main
*/

#include "rpg.h"
#include "math.h"

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

bullets_t *create_bullet(bullets_t *bullets, rpg_t *rpg, float speed)
{
    bullets_t *tmp = bullets;
    if (bullets == NULL) {
        bullets = malloc(sizeof(bullets_t));
        bullets->pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 2));
        bullets->speed = speed;
        bullets->sprite = sfSprite_create();
        bullets->texture = sfTexture_createFromFile("assets/01.png", NULL);
        bullets->scale = (sfVector2f){1.0,1.0};
        bullets->rect = (sfIntRect){0, 0, 100, 100};
        bullets->next = NULL;
        sfSprite_setTextureRect(bullets->sprite, bullets->rect);
        sfSprite_setTexture(bullets->sprite, bullets->texture, sfTrue);
        sfSprite_setScale(bullets->sprite, bullets->scale);
        sfSprite_setPosition(bullets->sprite, bullets->pos);
        return bullets;
    }
    else {
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = malloc(sizeof(bullets_t));
    tmp->next->pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 2));
    tmp->next->speed = speed;
    tmp->next->sprite = sfSprite_create();
    tmp->next->texture = sfTexture_createFromFile("assets/bullet.png", NULL);
    tmp->next->scale = (sfVector2f){1.25, 1.35};
    tmp->next->rect = (sfIntRect){0, 0, 100, 100};
    tmp->next->next = NULL;
    sfSprite_setTextureRect(tmp->next->sprite, tmp->next->rect);
    sfSprite_setTexture(tmp->next->sprite, tmp->next->texture, sfTrue);
    sfSprite_setScale(tmp->next->sprite, tmp->next->scale);
    sfSprite_setPosition(tmp->next->sprite, tmp->next->pos);
    }
    return bullets;

}

bullets_t *delete_outmap_bullet(bullets_t *bullets)
{
    bullets_t *tmp = bullets;
    while (tmp->next != NULL) {
        if (tmp->next->pos.x > 1920 && tmp->next->next == NULL) {
                tmp->next = NULL;
                return bullets;
            }

        tmp = tmp->next;
    }
    return bullets;
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
    while (tmp != NULL) {
        if (i == index) {
            tmp->next = tmp->next->next;
            return;
        }
        i++;
        tmp = tmp->next;
    }
}

void hit_boss(rpg_t *rpg, bullets_t *bullets)
{
    sfVector2f sprite_pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 0));
    sfVector2f sprite_size = sfSprite_getScale(gl_get_sprite(rpg->glib, 0));
    sfVector2f top_right = (sfVector2f){sprite_pos.x, sprite_pos.y};
    sfVector2f bottom_left = (sfVector2f){sprite_pos.x + sprite_size.x * 100, sprite_pos.y + sprite_size.y * 100};

    printf("sprite top right = %f, %f\n", top_right.x, top_right.y);
    printf("sprite bottom left = %f, %f\n", bottom_left.x, bottom_left.y);
    void *tmp = bullets;
    //SPRITE IS reversed

    //printf("sprite top left = %f, %f\n", sprite_pos.x, sprite_pos.y);
    //printf("sprite bottom right = %f, %f", sprite_pos.x + sprite_size.x * 100, sprite_pos.y + sprite_size.y * 100);
    //printf("sprite size = %f, %f\n", sprite_size.x, sprite_size.y);
    //bullets_t *tmp = bullets;
    //int i = 0;
    //while (tmp != NULL) {
    //    if (tmp->pos.x > sprite_pos.x && tmp->pos.x < sprite_pos.x + sprite_size.x * 100) {
    //        if (tmp->pos.y > sprite_pos.y && tmp->pos.y < sprite_pos.y + sprite_size.y * 100) {
    //            delete_element(bullets, i);
    //            printf(":::hit\n");
    //        }
    //    }
    //    i++;
    //    tmp = tmp->next;
    //}
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
        if (click_in_rect(hitbox, tmp->pos) == 1) {
            delete_element(bullets, i);
            printf(":::hit\n");
        }
        tmp = tmp->next;
        i++;
    }
}

    // if (rect_scale.x > 0 && rect_scale.y < 0) {
    //     if (pos.x > rect_pos.x && pos.x < rect_pos.x + rect_scale.x * 100) {
    //         if (pos.y < rect_pos.y && pos.y > rect_pos.y + rect_scale.y * 100) {
    //             printf("click in rect\n");
    //         }
    //     }
    // }
    // //if scale x is negative and y is positive
    // if (rect_scale.x < 0 && rect_scale.y > 0) {
    //     if (pos.x < rect_pos.x && pos.x > rect_pos.x + rect_scale.x * 100) {
    //         if (pos.y > rect_pos.y && pos.y < rect_pos.y + rect_scale.y * 100) {
    //             printf("click in rect\n");
    //         }
    //     }
    // }
    // //if scale x is positive and y is positive
    // if (rect_scale.x > 0 && rect_scale.y > 0) {
    //     if (pos.x > rect_pos.x && pos.x < rect_pos.x + rect_scale.x * 100) {
    //         if (pos.y > rect_pos.y && pos.y < rect_pos.y + rect_scale.y * 100) {
    //             printf("click in rect\n");
    //         }
    //     }
    // }
    // //if scale x is negative and y is negative
    // if (rect_scale.x < 0 && rect_scale.y < 0) {
    //     if (pos.x < rect_pos.x && pos.x > rect_pos.x + rect_scale.x * 100) {
    //         if (pos.y < rect_pos.y && pos.y > rect_pos.y + rect_scale.y * 100) {
    //             printf("click in rect\n");
    //         }
    //     }
    // }

int check_colision_1(sfVector2f rect_pos, sfVector2f rect_scale, sfVector2f pos)
{
    if (pos.x > rect_pos.x && pos.x < rect_pos.x + rect_scale.x * 100) {
        if (pos.y < rect_pos.y && pos.y > rect_pos.y + rect_scale.y * 100) {
            return (1);
        }
    }
    return (0);
}

int check_colision_2(sfVector2f rect_pos, sfVector2f rect_scale, sfVector2f pos)
{
    if (pos.x < rect_pos.x && pos.x > rect_pos.x + rect_scale.x * 100) {
        if (pos.y > rect_pos.y && pos.y < rect_pos.y + rect_scale.y * 100) {
            return (1);
        }
    }
    return (0);
}

int check_colision_3(sfVector2f rect_pos, sfVector2f rect_scale, sfVector2f pos)
{
    if (pos.x > rect_pos.x && pos.x < rect_pos.x + rect_scale.x * 100) {
        if (pos.y > rect_pos.y && pos.y < rect_pos.y + rect_scale.y * 100) {
            return (1);
        }
    }
    return (0);
}

int check_colision_4(sfVector2f rect_pos, sfVector2f rect_scale, sfVector2f pos)
{
    if (pos.x < rect_pos.x && pos.x > rect_pos.x + rect_scale.x * 100) {
        if (pos.y < rect_pos.y && pos.y > rect_pos.y + rect_scale.y * 100) {
            return (1);
        }
    }
    return (0);
}

int  click_in_rect(sfRectangleShape *rect, sfVector2f pos)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);
    sfVector2f rect_scale = sfRectangleShape_getScale(rect);
    if (rect_scale.x > 0 && rect_scale.y < 0)
        return (check_colision_1(rect_pos, rect_scale, pos));
    if (rect_scale.x < 0 && rect_scale.y > 0)
        return (check_colision_2(rect_pos, rect_scale, pos));
    if (rect_scale.x > 0 && rect_scale.y > 0)
        return (check_colision_3(rect_pos, rect_scale, pos));
    if (rect_scale.x < 0 && rect_scale.y < 0)
        return (check_colision_4(rect_pos, rect_scale, pos));
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
    bullets_t *bullets = malloc(sizeof(bullets_t));
    bullets->pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 2));
    bullets->speed = 10;
    bullets->sprite = sfSprite_create();
    bullets->texture = sfTexture_createFromFile("assets/bullet.png", NULL);
    bullets->scale = (sfVector2f){1.25, 1.35};
    bullets->rect = (sfIntRect){0, 0, 100, 100};
    bullets->next = NULL;
    //delete_element(bullets, 0);
    /*
    sfVector2f sprite_pos = sfSprite_getPosition(gl_get_sprite(rpg->glib, 0));
    sfVector2f sprite_size = sfSprite_getScale(gl_get_sprite(rpg->glib, 0));
    sfVector2f top_right = (sfVector2f){sprite_pos.x, sprite_pos.y};
    sfVector2f bottom_left = (sfVector2f){sprite_pos.x + sprite_size.x * 100, sprite_pos.y + sprite_size.y * 100};
    */
    //display collision box
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, (sfVector2f){1500, 300});
    sfRectangleShape_setSize(rect, (sfVector2f){100, 100});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfRed);
    sfRectangleShape_setOutlineThickness(rect, 5);
    sfRectangleShape_setScale(rect, (sfVector2f){-3.0, 3.0});




    while (sfRenderWindow_isOpen(rpg->glib->window->window)) {
        print_framerate();
        sfRenderWindow_clear(rpg->glib->window->window, sfBlack);
        gl_draw_sprite(rpg->glib, 1);
        gl_draw_sprite(rpg->glib, 0);
        gl_draw_sprite(rpg->glib, 2);
        move_player(rpg, clock);
        if (sfKeyboard_isKeyPressed(sfKeySpace) && sfClock_getElapsedTime(clock_shoot).microseconds / 200000.0 > 1) {
            bullets = create_bullet(bullets, rpg, 10);
            sfClock_restart(clock_shoot);
        }
        bullets_t *tmp = bullets;
        while (tmp->next != NULL) {
            tmp = tmp->next;
            tmp->pos.x += tmp->speed;
            sfSprite_setPosition(tmp->sprite, tmp->pos);
            sfRenderWindow_drawSprite(rpg->glib->window->window, tmp->sprite, NULL);
        }
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->glib->window->window);
            sfVector2f mouse_pos_f = (sfVector2f){mouse_pos.x, mouse_pos.y};
            click_in_rect(rect, mouse_pos_f);
        }
        //bullets = delete_outmap_bullet(bullets);
        //hit_boss(rpg, bullets);
        sfRenderWindow_drawRectangleShape(rpg->glib->window->window, rect, NULL);
        collision(rect, bullets);
        //hit_by_bullet(gl_get_sprite(rpg->glib, 0), bullets);
        //print_len_list(bullets);
        gl_check_events(rpg->glib->window, rpg->glib->events, rpg);
        sfRenderWindow_display(rpg->glib->window->window);
    }
}
