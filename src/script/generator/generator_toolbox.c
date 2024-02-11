/*
** EPITECH PROJECT, 2019
** generator_toolbox.c
** File description:
** toolbox of the generator
*/

#include "lib.h"

int random_range(int min, int max)
{
    int nb = rand() % max + min;

    return (nb);
}

char *re_init_buffer(char *buffer, int len)
{
    int i = 0;

    while (i < len) {
        buffer[i] = '\0';
        ++i;
    }
    return (buffer);
}

char *nb_to_str(int nb, char *res, bool re_init)
{
    char *reset = res;

    if (re_init) {
        res = re_init_buffer(res, 5);
        re_init = false;
    }
    if (10 <= nb)
        res = nb_to_str(nb / 10, ++res, re_init);
    res = reset;
    res[0] = nb % 10 + 48;
    return (res);
}