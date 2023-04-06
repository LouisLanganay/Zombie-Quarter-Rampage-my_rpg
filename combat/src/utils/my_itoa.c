/*
** EPITECH PROJECT, 2023
** combat
** File description:
** my_itoa
*/

char *my_itoa(int nb)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * 100);
    if (nb < 0) {
        str[i] = '-';
        i++;
        nb = nb * -1;
    }
    while (nb > 0) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i++;
    }str[i] = '\0';
    for (j = 0; j < i / 2; j++) {
        k = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = k;
    }
    return (str);
}
