/*
** EPITECH PROJECT, 2022
** task03
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int count_character = 0;

    for (int i = 0 ; str[i] != '\0' ; i ++) {
        count_character++;
    }
    return (count_character);
}
