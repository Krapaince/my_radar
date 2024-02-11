/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** display the aircraft
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"

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
    if (aircraft->x0 < aircraft->x1 && aircraft->x == 1)
        ++r_air;
    else if (aircraft->x0 > aircraft->x1 && aircraft->x == 0)
        ++r_air;
    if (aircraft->y0 < aircraft->y1 && aircraft->y == 1)
        ++r_air;
    else if (aircraft->y0 > aircraft->y1 && aircraft->y == 0)
        ++r_air;
    return (r_air);
}

void display_aircraft(csfml_t *csfml, aircraft_t **aircraft)
{
    sfVector2f position = {0, 0};
    aircraft_t *reset = *aircraft;
    aircraft_t *previous = NULL;

    while (*aircraft) {
        if (update_pos(*aircraft) != 2) {
            position.x = (*aircraft)->x0 - 10;
            position.y = (*aircraft)->y0 - 10;
            sfSprite_setOrigin(csfml->aircraft, position);
            sfSprite_setPosition(csfml->aircraft, position);
            sfSprite_setRotation(csfml->aircraft, (*aircraft)->angle);
            sfRenderWindow_drawSprite(csfml->window, csfml->aircraft, NULL);
            previous = *aircraft;
            *aircraft = (*aircraft)->next;
        } else {
            printf("\nAircraft\n%.2f, %f.2\n%.2f %.2f", (*aircraft)->x0, (*aircraft)->y0, (*aircraft)->x1, (*aircraft)->y1);
            remove_aircraft(aircraft, &previous, &reset);
        }
    }
    *aircraft = reset;
}