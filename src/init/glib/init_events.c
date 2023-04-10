/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_events
*/

#include "rpg.h"

void init_events(rpg_t *rpg)
{
    rpg->glib->events = NULL;
    gl_create_event(rpg->glib, EVENT_KEY_RELEASED,
        sfEvtKeyReleased, e_key_released);
    gl_create_event(rpg->glib, EVENT_KEY_PRESSED,
        sfEvtKeyPressed, e_key_pressed);
    gl_create_event(rpg->glib, EVENT_WINDOW_CLOSE,
                    sfEvtClosed, e_close);
    gl_create_event(rpg->glib, EVENT_INVENTORY_OPEN,
                    sfEvtKeyPressed, e_open_inventory);
    gl_create_event(rpg->glib, EVENT_DIALOGUE_CHOICE,
                    sfEvtKeyPressed, e_dialogue);
}
