/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** my_is_a_float
*/

int my_is_a_float(char *str)
{
    for (int i = 0; str[i] != ','; i++) {
        if (str[i] == '.')
            return 1;
    }
    return 0;
}
