/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** load_save
*/

#include "rpg.h"

int load_save_settings(settings_t *settings, parsed_data_t *data)
{
    data = data->value.p_obj;
    settings->game_language = GET_SAVE_GAMELANGUAGE;
    return (0);
}

int load_save_player(player_t *player, parsed_data_t *data)
{
    data = data->value.p_obj;
    player->pos.x = jp_search(data, "pos.x")->value.p_int;
    player->pos.y = jp_search(data, "pos.y")->value.p_int;
    player->hp = jp_search(data, "hp")->value.p_int;
    return 0;
}

int load_save_save(save_t *save, parsed_data_t *data)
{
    data = data->value.p_obj;
    save->format = jp_search(data, "format")->value.p_str;
    save->name = jp_search(data, "name")->value.p_str;
    save->path = jp_search(data, "path")->value.p_str;
    return (0);
}

int load_save(rpg_t *rpg, char *path)
{
    parsed_data_t *data = jp_parse(path);
    if (data == NULL)
        return (84);
    if (load_save_settings(rpg->settings, jp_search(data, "settings")) != 0)
        return (84);
    if (load_save_save(rpg->save, jp_search(data, "save_file")) != 0)
        return (84);
    if (load_save_player(rpg->player, jp_search(data, "player")) != 0)
        return (84);
    return (0);
}
