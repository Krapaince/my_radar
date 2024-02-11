/*
** EPITECH PROJECT, 2019
** collision_detection.c
** File description:
** detect if aircraft colide
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"

bool aircraft_in_tower_range(aircraft_t *aircraft, tower_t *tower)
{
    float delta_x = 0;
    float delta_y = 0;

    while (tower) {
        delta_x = tower->x - (aircraft->x0 + aircraft->width / 2);
        delta_y = tower->y - (aircraft->y0 + aircraft->height / 2);
        if (pow(delta_x, 2) + pow(delta_y, 2) <= pow(tower->radius, 2))
            return (true);
        tower = tower->next;
    }
    return (false);
}

void collision_detection(aircraft_t *one, aircraft_t *two)
{
    sfVector2f delta =
    {fabs(one->x0 + one->width / 2 - (two->x0 + two->width / 2)),
    fabs(two->y0 + two->height / 2 - (one->y0 + one->height / 2))};
    sfVector2f size = {
    (one->width + two->width) / 2,
    (one->height + two->height) / 2};

    if (delta.x <= size.x
    && delta.y <= size.y) {
        one->destroy = 1;
        two->destroy = 1;
    }
}