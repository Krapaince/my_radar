/*
** EPITECH PROJECT, 2019
** simulation.c
** File description:
** launch the simulation
*/

#include "lib.h"
#include "struct.h"
#include "error.h"
#include <csfml.h>
#include "simulation.h"

int loop_game(csfml_t *csfml, aircraft_t **aircraft, tower_t **tower)
{
    while (sfRenderWindow_isOpen(csfml->window)) {
        sfRenderWindow_clear(csfml->window, sfBlack);
        display_aircraft(csfml, aircraft);
        sfRenderWindow_display(csfml->window);
        event_check(csfml, csfml->event);
        (void)tower;
    }
    return (0);
}

int launch_simulation(aircraft_t **aircraft, tower_t **tower)
{
    csfml_t *csfml = init_csfml(WIDTH, HEIGHT);

    if (!csfml)
        return (84);
    if (loop_game(csfml, aircraft, tower) == 84)
        return (84);
    destroy_csfml(csfml);
    return (0);
}