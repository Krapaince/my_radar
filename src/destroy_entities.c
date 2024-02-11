/*
** EPITECH PROJECT, 2019
** destry_entities.c
** File description:
** free the entitires
*/

#include "lib.h"
#include "struct.h"

void destroy_tower(tower_t *tower)
{
    tower_t *previous = NULL;

    while (tower) {
        previous = tower;
        tower = tower->next;
        free(previous);
    }
}

void destroy_aircraft(aircraft_t *aircraft)
{
    aircraft_t *previous = NULL;

    while (aircraft) {
        previous = aircraft;
        aircraft = aircraft->next;
        free(previous);
    }
}

void destroy(aircraft_t *aircraft, tower_t *tower)
{
    destroy_tower(tower);
    destroy_aircraft(aircraft);
}