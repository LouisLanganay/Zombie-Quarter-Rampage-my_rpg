/*
** EPITECH PROJECT, 2023
** glib
** File description:
** gl_create_scene
*/

#include "../gl.h"

static int handle_error(int id)
{
    if (id < 0)
        return write(2, "(gl_create_scene) Scene id must be positive\n", 44);
    return (0);
}

static int gl_create_scene_check_id(GLib_t *glib, int id)
{
    scenes_t *tmp = glib->scenes;
    while (tmp) {
        if (tmp->id == id)
            return write(2, "(gl_create_scene) Scene id already exist\n", 41);
        tmp = tmp->next;
    }
    return (0);
}

int gl_create_scene(GLib_t *glib, int id)
{
    if (handle_error(id) != 0)
        return (84);
    if (gl_create_scene_check_id(glib, id) != 0)
        return (84);
    scenes_t *tmp = malloc(sizeof(*tmp));
    tmp->id = id;
    tmp->buttons = malloc(sizeof(int) * 100);
    int x = SCENE_ARRAY_SIZE;
    for (int i = 0; i < x; i++)
        tmp->buttons[i] = 0;
    tmp->texts = malloc(sizeof(int) * 100);
    for (int i = 0; i < x; i++)
        tmp->texts[i] = 0;
    tmp->sprites = malloc(sizeof(int) * 100);
    for (int i = 0; i < x; i++)
        tmp->sprites[i] = 0;

    tmp->next = glib->scenes;
    glib->scenes = tmp;
    return (0);
}
