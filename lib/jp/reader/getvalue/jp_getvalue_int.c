/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** jp_getvalue_int
*/

#include "../../jp.h"

void jp_getvalue_int(char **str, parsed_data_t *data)
{
    int nb = my_getnbr(*str);
    double nb_float = my_getnbr_float(*str);
    int is_float = my_is_a_float(*str);

    for (; **str == '.' || **str == '-' ||
        (**str >= '0' && **str <= '9'); *str += 1);

    if (is_float == 1) {
        data->type = p_float;
        data->value.p_float = nb_float;
    } else {
        data->type = p_int;
        data->value.p_int = nb;
    }
}
