/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main my_radar
*/

#include "lib.h"
#include "struct.h"
#include "proto.h"

int main(int ac, char **ag)
{
    if (ac != 2) {
        cat("resources/error_my_radar.txt", STDERR_FILENO);
        return (84);
    }
    else if (my_strcmp(ag[1], "-h") == 0) {
        return (cat("resources/usage_my_radar.txt", STDOUT_FILENO));
    } else {
        if (traffic_simulation(ag[1]) == 84)
            return (84);
    }
    return (0);
}