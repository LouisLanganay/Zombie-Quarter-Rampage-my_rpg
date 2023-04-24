/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save
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

void save(rpg_t *rpg)
{
    save_settings(rpg);
    save_game(rpg);
    save_player(rpg);
    save_quests_in_progress(rpg);
    save_quests_completed(rpg);
    save_npc_interactions(rpg);
    save_chests_opened(rpg);
    save_game_timeline(rpg);
    save_save(rpg);
    save_combats(rpg);
    reload_saves_texts(rpg);
}
