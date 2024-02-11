/*
** EPITECH PROJECT, 2019
** collision_detection.c
** File description:
** detect if aircraft colide
*/

#include "lib.h"
#include "struct.h"

int aircraft_in_tower_range(aircraft_t *aircraft, tower_t *tower)
{
    int range = 0;
    float delta_x = 0;
    float delta_y = 0;

    while (tower) {
        delta_x = tower->x - (aircraft->x0 + aircraft->width / 2);
        delta_y = tower->y - (aircraft->y0 + aircraft->height / 2);
        if (pow(delta_x, 2) + pow(delta_y, 2) <= pow(tower->radius, 2))
            return (1);
        tower = tower->next;
    }
    return (0);
}

void collision_detection(aircraft_t *one, aircraft_t *two)
{
    if (one->x0 < two->x0 + two->width
    && one->x0 + one->width > two->x0
    && one->y0 < two->y + two->height
    && one->y0 + one->height > two->y0) {
        one->destroy = 1;
        two->destroy = 1;
    }
}