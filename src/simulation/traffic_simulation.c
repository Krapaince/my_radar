/*
** EPITECH PROJECT, 2019
** traffic simulation.c
** File description:
** land on/off the aircraft
*/

#include "lib.h"
#include "struct.h"
#include "script.h"
#include "csfml.h"
#include "quadtree.h"
#include "simulation.h"
#include "proto.h"
#include "error.h"

int traffic_simulation(char *filepath)
{
    aircraft_t *plane = NULL;
    tower_t *tower = NULL;
    int dt_max = 0;

    if (load(&plane, &tower, &dt_max, filepath) == 84) {
        my_putstr(E_LOAD, STDERR_FILENO);
        return (84);
    }
    if (launch_simulation(&plane, &tower, dt_max, filepath) == 84) {
        my_putstr(E_SIMU, STDERR_FILENO);
        return (84);
    }
    destroy(plane, tower);
    return (0);
}