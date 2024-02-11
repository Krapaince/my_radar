/*
** EPITECH PROJECT, 2019
** error_entities.c
** File description:
** check the error in the script for the entitties
*/

#include "lib.h"
#include "error.h"

int len_nb(int nb)
{
    int len = 1;

    while (9 < nb) {
        nb /= 10;
        ++len;
    }
    return (len);
}

int check_aircraft_param(char *buffer, int *i, int *n)
{
    int nb = 0;

    if (buffer[*i] != ' ') {
        my_putstr(E_SCRIPT_MISS_S, STDERR_FILENO);
        return (84);
    }
    nb = my_getnbr(&buffer[*i + 1]);
    if ((*n < 4 && (nb < 0 || (*n % 2 == 0 && 1920 < nb)
    || (*n % 2 == 1 && 1080 < nb))) || (*n == 4 && nb <= 0)
    || (*n == 5 && nb < 0)) {
        my_putstr(E_SCRIPT_PARAM, STDERR_FILENO);
        return (84);
    }
    *i += 1 + len_nb(nb);
    ++*n;
    return (0);
}

int check_aircraft(char *buffer)
{
    int len = my_strlen(buffer);
    int i = 1;
    int n = 0;

    while (n < 6 && i < len) {
        if (check_aircraft_param(buffer, &i, &n) == 84)
            return (84);
    }
    if (n != 6) {
        my_putstr(E_SCRIPT_MISS, STDERR_FILENO);
        return (84);
    }
    return (0);
}

int check_tower_param(char *buffer, int *i, int *n)
{
    int nb = 0;

    if (buffer[*i] != ' ') {
        my_putstr(E_SCRIPT_MISS_S, STDERR_FILENO);
        return (84);
    }
    nb = my_getnbr(&buffer[*i + 1]);
    if (nb < 0 || (*n == 0 && 1920 < nb) || (*n == 1 && 1080 < nb)
    || (*n == 2 && 100 < nb)) {
        my_putstr(E_SCRIPT_PARAM, STDERR_FILENO);
        return (84);
    }
    *i += 1 + len_nb(nb);
    ++*n;
    return (0);
}

int check_tower(char *buffer)
{
    int len = my_strlen(buffer);
    int i = 1;
    int n = 0;

    while (n < 3 && i < len) {
        if (check_tower_param(buffer, &i, &n) == 84)
            return (84);
    }
    if (n != 3) {
        my_putstr(E_SCRIPT_MISS, STDERR_FILENO);
        return (84);
    }
    return (0);
}