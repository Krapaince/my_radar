/*
** EPITECH PROJECT, 2019
** update_list.c
** File description:
** load the new aircraft, unload arrived aircraft
*/

#include "lib.h"
#include "struct.h"
#include "script.h"
#include "error.h"

void remove_aircraft(aircraft_t **current, aircraft_t **previous,
aircraft_t **reset)
{
    if (*previous == NULL) {
        *reset = (*current)->next;
        free(*current);
        (*current) = *reset;
    }
    else if (*previous) {
        (*previous)->next = (*current)->next;
        free(*current);
        (*current) = (*previous)->next;
    }
}

int update_pos(aircraft_t *aircraft)
{
    int r_air = 0;

    aircraft->x0 += aircraft->v_x;
    aircraft->y0 += aircraft->v_y;
    if (aircraft->x0 <= aircraft->x1 && aircraft->x == 1)
        ++r_air;
    else if (aircraft->x0 >= aircraft->x1 && aircraft->x == 0)
        ++r_air;
    if (aircraft->y0 <= aircraft->y1 && aircraft->y == 1)
        ++r_air;
    else if (aircraft->y0 >= aircraft->y1 && aircraft->y == 0)
        ++r_air;
    return (r_air);
}

void update_aircraft(aircraft_t **aircraft)
{
    aircraft_t *reset = *aircraft;
    aircraft_t *previous = NULL;

    while (*aircraft) {
        if (update_pos(*aircraft) == 2 || (*aircraft)->destroy == 1){
            remove_aircraft(aircraft, &previous, &reset);
        } else {
            previous = *aircraft;
            *aircraft = (*aircraft)->next;
        }
    }
    *aircraft = reset;
}