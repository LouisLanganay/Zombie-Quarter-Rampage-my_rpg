/*
** EPITECH PROJECT, 2022
** task05
** File description:
** task05
*/

#include "../jp.h"

static int invert_nb_float(char *str, int *c)
{
    int invert = 1;

    while (str[*c] == '-' || str[*c] == '+'){
        if (str[*c] == '-'){
            invert = invert * -1;
        }
        (*c)++;
    }
    return invert;
}

static double revert_nbr(int i, char *str, double number)
{
    int p = 1;
    for (int x = i; str[x] != '\0' && str[x] != ',' &&
        str[x] != '\n' && str[x] != '}'; x++) {
        if (str[x] >= '0' && str[x] <= '9') {
            double nb = str[x] -'0';
            number += nb / my_compute_power_rec(10, p);
            p++;
        }
    }
    return number;
}

double my_getnbr_float(char *str)
{
    int c = 0;
    double number = 0;
    int invert = invert_nb_float(str, &c);
    int i = 0;
    while (str[i] != '.' && str[i] != '\0' &&
        str[i] != ',' && str[i] != '\n' && str[i] != '}') {
        if (str[i] >= '0' && str[i] <= '9')
            number = (number * 10) + str[i] -'0';
        if (number > 2147483647 || number < -2147483647)
            return 0;
        i++;
    }
    number = revert_nbr(i, str, number);
    return (number * invert);
}
