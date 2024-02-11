/*
** EPITECH PROJECT, 2019
** param.c
** File description:
** get the argument
*/

#include <stddef.h>
#include "struct.h"
#include <getopt.h>

static int read_args(generator_t *generator ,int ac, char *av,
    struct option *long_opt)
{
    const char *short_opt = "n:a:t:";
    int option = 0;
    int status = 1;
    int index = 0;

    option = getopt_long(ac, av, short_opt, long_opt, &index);
    while (option != -1 && option != '?') {
        option = getopt_long(ac, av, short_opt, long_opt, &index);

    }
    if (option == '?') {
        status = 0;
    }
    return (status);
}

static int get_options(generator_t *generator, int ac, char **av)
{
    struct option long_option[10] = {
        {"name", required_argument, NULL, 0},
        {"aircraft", required_argument, NULL, 0},
        {"dt_a_min", required_argument, NULL, 0},
        {"dt_a_max", required_argument, NULL, 0},
        {"speed_min", required_argument, NULL, 0},
        {"speed_max", required_argument, NULL, 0},
        {"tower", required_argument, NULL, 0},
        {"radius_min", required_argument, NULL, 0},
        {"redius_max", required_argument, NULL, 0},
        {NULL, 0, NULL, 0}};
    int status = read_args(generator, ac, av, long_option);

    return (status);
}

int parse_argument(generator_t *generator, int ac, char **av)
{
    int status = get_options(generator, ac, av);

    return (status);
}