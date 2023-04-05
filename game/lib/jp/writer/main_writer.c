/*
** EPITECH PROJECT, 2023
** json-parser
** File description:
** main_writer
*/

#include "../jp.h"

void jp_write(char *filepath, parsed_data_t *data)
{
    int fd = open(filepath, O_RDWR | O_CREAT | O_TRUNC);
    if (fd == -1)
        return;
    jp_writedata(fd, data, 1);
    close(fd);
}
