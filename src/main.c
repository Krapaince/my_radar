/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main my_radar
*/

#include "lib.h"
#include "struct.h"
#include "proto.h"

void error(int ac)
{
    my_putstr("./my_radar: bad arguments: ", STDOUT_FILENO);
    my_putnbr(ac - 1, STDOUT_FILENO);
    my_putstr(" given but  1 is required\nretry with -h", STDOUT_FILENO);
}

void usage(void)
{
    my_putstr("Air traffic simulation panel\n\n", STDOUT_FILENO);
    my_putstr("USAGE:\n", STDOUT_FILENO);
    my_putstr("\t./radar [OPTION]\n\n", STDOUT_FILENO);
    my_putstr("OPTION:\n", STDOUT_FILENO);
    my_putstr("\t-h\t\tprint the usage and quit\n\n", STDOUT_FILENO);
    my_putstr("USER INTERACTIONS: (possible every second)\n", STDOUT_FILENO);
    my_putstr("\t'L'\t\tenable/disabled hitboxes and areas\n", STDOUT_FILENO);
    my_putstr("\t'S'\t\tenable/disabled sprites", STDOUT_FILENO);
}

int main(int ac, char **ag)
{
    if (ac != 2) {
        error(ac);
        return (84);
    }
    else if (my_strcmp(ag[1], "-h") == 0) {
        usage();
        return (0);
    } else {
        if (traffic_simulation(ag[1]) == 84)
            return (84);
    }
    return (0);
}