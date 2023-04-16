/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save_player
*/

#include "rpg.h"

static void add_node_to_my_arr(parsed_data_t *my_arr, int nb)
{
    if (my_arr == NULL) return;
    parsed_data_t *tmp = my_arr;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(parsed_data_t));
    if (tmp->next == NULL) return;
    tmp->next->type = p_int;
    tmp->next->value.p_int = nb;
    tmp->next->next = NULL;
}

static void save_player_inventory(
    player_t *player,
    parsed_data_t *data,
    rpg_t *rpg
)
{
    parsed_data_t *my_arr = malloc(sizeof(parsed_data_t));
    my_arr->type = p_int;
    my_arr->value.p_int = player->inventory->items[0];
    my_arr->next = NULL;

    for (int i = 1; i < INVENTORY_SIZE; i++) {
        add_node_to_my_arr(my_arr, player->inventory->items[i]);
    }
    jp_search(data, "inventory.items")->value.p_arr = my_arr;
}

void save_player(rpg_t *rpg)
{
    parsed_data_t *data = jp_parse(rpg->save->path);
    parsed_data_t *player = jp_search(data, "player")->value.p_obj;
    jp_search(player, "pos.x")->value.p_int = rpg->player->pos.x;
    jp_search(player, "pos.y")->value.p_int = rpg->player->pos.y;
    jp_search(player, "hp")->value.p_int = rpg->player->hp;
    jp_search(player, "hunger")->value.p_int = rpg->player->hunger;
    save_player_inventory(rpg->player, player, rpg);
    jp_write(rpg->save->path, data);
}
