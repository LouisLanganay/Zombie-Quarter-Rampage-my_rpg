/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** reset_a_save
*/

#include "rpg.h"

void reset_a_save(rpg_t *rpg)
{
    parsed_data_t *def = jp_parse("resources/saves/default.json");
    parsed_data_t *save = jp_parse(rpg->save->path);

    parsed_data_t *header = jp_search(def, "save_file")->value.p_obj;
    parsed_data_t *header2 = jp_search(save, "save_file")->value.p_obj;

    jp_search(header, "path")->value.p_str = jp_search(header2, "path")->value.p_str;
    jp_search(header, "format")->value.p_str = jp_search(header2, "format")->value.p_str;
    jp_search(header, "name")->value.p_str = jp_search(header2, "name")->value.p_str;
    jp_search(header, "played")->value.p_bool = jp_search(header2, "played")->value.p_bool;
    jp_write(rpg->save->path, def);
}
