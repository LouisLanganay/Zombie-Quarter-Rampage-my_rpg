/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** save_save
*/

#include "rpg.h"

void save_save(rpg_t *rpg)
{
    parsed_data_t *save = jp_parse(rpg->save->path);
    jp_search(save, "save_file.played")->value.p_bool = b_true;
    jp_write(rpg->save->path, save);
}
