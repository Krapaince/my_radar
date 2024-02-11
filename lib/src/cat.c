/*
** EPITECH PROJECT, 2019
** cat.c
** File description:
** cat a file
*/

#include "lib.h"

int cat(char *filepath, int std)
{
    int fd = open(filepath, O_RDONLY, S_IRWXU);
    int r_read = 1;
    char buffer[256];

    if (fd == -1) {
        my_putstr("Error cat\n", STDERR_FILENO);
        return (84);
    }
    while (0 < r_read) {
        r_read = read(fd, buffer, 255);
        buffer[r_read] = '\0';
        my_putstr(buffer, std);
    }
    close(fd);
    return (0);
}