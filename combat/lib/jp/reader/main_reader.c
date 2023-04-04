/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** main_reader
*/

#include "../jp.h"

parsed_data_t *jp_parse(char *filepath)
{
    char *str;
    load_file_in_str(filepath, &str);
    parsed_data_t *data = load_object(&str);

    return (data);
}
