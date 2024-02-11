/*
** EPITECH PROJECT, 2019
** load_map.c
** File description:
** load the script
*/

#include "lib.h"
#include "struct.h"
#include "proto.h"
#include "script.h"
#include "error.h"

int load(aircraft_t **plane, tower_t **tower, int *dt_current, char *filepath)
{
    if (error_script(filepath) == 84) {
        my_putstr(E_SCRIPT, STDERR_FILENO);
        return (84);
    }
    if (load_tower(tower, filepath) == 84) {
        my_putstr(E_LOAD_TOWER, STDERR_FILENO);
        return (84);
    }
    if (load_aircraft(plane, filepath, 0, dt_current) == 84) {
        my_putstr(E_LOAD_AIRCRAFT, STDERR_FILENO);
        return (84);
    }
    return (0);
}