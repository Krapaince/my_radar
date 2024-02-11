/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** look at the error in the script
*/

#include "lib.h"
#include "struct.h"
#include "proto.h"
#include "script.h"
#include  "error.h"

void destroy_error(error_t *error)
{
    free(error->buffer);
    fclose(error->script);
}

int aircraft_after_tower(char *buffer, int *atot)
{
    if (buffer[0] == 'T')
        *atot = 1;
    if (buffer[0] == 'A' && *atot) {
        my_putstr(E_SCRIPT_ATA, STDERR_FILENO);
        return (84);
    }
    return (0);
}

int check_line(char *buffer, int *atot)
{
    int err = 0;

    if (buffer[0] == 'A' && check_aircraft(buffer) == 84) {
        my_putstr(E_SCRIPT_AIRCRAFT, STDERR_FILENO);
        err = 84;
    }
    if (buffer[0] == 'T' && check_tower(buffer) == 84) {
        my_putstr(E_SCRIPT_TOWER, STDERR_FILENO);
        err = 84;
    }
    if (aircraft_after_tower(buffer, atot) == 84)
        err = 84;
    if (buffer[0] != 'A' && buffer[0] != 'T') {
        my_putstr(E_SCRIPT_TYPE, STDERR_FILENO);
        err = 84;
    }
    if (err == 84)
        return (84);
    return (0);
}

int error_script(char *filepath)
{
    error_t error[] = {{fopen(filepath, "r"), NULL, 0, 0, 1}};

    if (!error->script) {
        my_putstr(E_OPEN, STDERR_FILENO);
        return (84);
    }
    while (getline(&error->buffer, &error->n, error->script) != -1) {
        if (check_line(error->buffer, &error->atot) == 84) {
            my_putnbr(error->line, STDERR_FILENO);
            my_putstr(E_LINE, STDERR_FILENO);
            return (84);
        }
        ++error->line;
    }
    if (error->line == 1) {
        my_putstr(E_SCRIPT_EMPTY, STDERR_FILENO);
        return (84);
    }
    destroy_error(error);
    return (0);
}