/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_glib
*/

#include "rpg.h"

void init_glib(rpg_t *rpg)
{
    rpg->glib = malloc(sizeof(GLib_t));
    init_window(rpg);
    init_events(rpg);
}
