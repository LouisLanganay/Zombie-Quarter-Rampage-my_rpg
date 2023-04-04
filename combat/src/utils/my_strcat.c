/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** my_strcat
*/

int my_strlen(char *str);

char *my_strcat(char *dest, char const *src)
{
    int destlen = my_strlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[i + destlen] = src[i];
        i++;
    }
    dest[i + destlen] = '\0';
    return dest;
}
