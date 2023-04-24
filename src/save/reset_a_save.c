/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** reset_a_save
*/

#include "rpg.h"

static void reload_saves_texts(rpg_t *rpg)
{
    parsed_data_t *d1 = jp_parse("saves/save1.json");
    parsed_data_t *d2 = jp_parse("saves/save2.json");
    parsed_data_t *d3 = jp_parse("saves/save3.json");
    sfText *txt1 = gl_get_text(rpg->glib, TXT_SAVE1);
    sfText *txt2 = gl_get_text(rpg->glib, TXT_SAVE2);
    sfText *txt3 = gl_get_text(rpg->glib, TXT_SAVE3);
    char *str1 = jp_search(d1, "save_file.name")->value.p_str;
    char *str2 = jp_search(d2, "save_file.name")->value.p_str;
    char *str3 = jp_search(d3, "save_file.name")->value.p_str;

    sfText_setString(txt1, (jp_search(d1, "save_file.played")->value.p_bool
        == b_true ? str1 : "Empty"));
    sfText_setString(txt2, (jp_search(d2, "save_file.played")->value.p_bool
        == b_true ? str2 : "Empty"));
    sfText_setString(txt3, (jp_search(d3, "save_file.played")->value.p_bool
        == b_true ? str3 : "Empty"));
}

void reset_a_save(rpg_t *rpg)
{
    parsed_data_t *def = jp_parse("resources/saves/default.json");
    parsed_data_t *save = jp_parse(rpg->save->path);

    parsed_data_t *header = jp_search(def, "save_file")->value.p_obj;
    parsed_data_t *header2 = jp_search(save, "save_file")->value.p_obj;

    jp_search(header,
        "path")->value.p_str = jp_search(header2, "path")->value.p_str;
    jp_search(header,
        "format")->value.p_str = jp_search(header2, "format")->value.p_str;
    jp_search(header,
        "name")->value.p_str = jp_search(header2, "name")->value.p_str;
    jp_write(rpg->save->path, def);
    reload_saves_texts(rpg);
}
