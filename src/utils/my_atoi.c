/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** my_atoi
*/

static int invert_nb(char const *str, int *c)
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

int my_atoi(char const *str)
{
    long int number = 0;
    int c = 0;
    int invert = invert_nb(str, &c);
    for (int x = 0 + c; str[x] != '\0'; x++){
        if (str[x] >= '0' && str[x] <= '9'){
            number = (number * 10) + str[x] -'0';
        }
        if (number > 2147483647 || number < -2147483647)
            return 0;
    }
    if (number > 2147483647 || number < -2147483647)
        return 0;
    return (number * invert);
}
