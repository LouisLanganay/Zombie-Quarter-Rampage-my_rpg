/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int count_character = 0;

    for (int i = 0 ; str[i] != '\0' ; i ++) {
        count_character++;
    }
    return (count_character);
}
