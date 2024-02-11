/*
** EPITECH PROJECT, 2019
** simulation.c
** File description:
** launch the simulation
*/

#include "lib.h"
#include "struct.h"
#include "error.h"
#include "csfml.h"
#include "quadtree.h"
#include "simulation.h"
#include "script.h"

int loop_game(csfml_t *csfml, aircraft_t **aircraft, tower_t *tower,
char *filepath)
{
    qtree_t *root = qtree_create(0, 0, WIDTH, HEIGHT);

    while (sfRenderWindow_isOpen(csfml->window)) {
        if (!qtree(*aircraft, root)) {
            my_putstr(E_QTREE, STDERR_FILENO);
            return (84);
        }
        if (!display(csfml, *aircraft, tower, root))
            return (84);
        if (csfml->sec == 1 && load_aircraft(aircraft, filepath,
        csfml->dt, NULL) == 84)
            return (84);
        update_aircraft(aircraft);
        event_check(csfml, csfml->event, *aircraft);
    }
    return (0);
}

int launch_simulation(aircraft_t **aircraft, tower_t **tower, int dt_max,
char *filepath)
{
    csfml_t *csfml = alloc_csfml(WIDTH, HEIGHT);

    if (!csfml)
        return (84);
    csfml->dt_max = dt_max;
    sfClock_restart(csfml->timer);
    if (loop_game(csfml, aircraft, *tower, filepath) == 84)
        return (84);
    destroy_csfml(csfml);
    return (0);
}