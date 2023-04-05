/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** load_file_in_mem
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void load_file_in_str(char const *filepath, char **str)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    int size = 0;

    stat(filepath, &st);
    size = st.st_size;
    *str = malloc(sizeof(char) * (size + 1));
    read(fd, *str, size);
    (*str)[size] = '\0';
    close(fd);
}
