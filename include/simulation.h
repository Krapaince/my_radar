/*
** EPITECH PROJECT, 2019
** simulation.h
** File description:
** contain the proto of the simlation folder
*/

#ifndef SIMULATION_H_
    #define SIMULATION_H_
    int update_aircraft(aircraft_t **aircraft);
    int loop_game(csfml_t *csfml, aircraft_t **aircraft, tower_t *tower,
    char *filepath);
    int launch_simulation(aircraft_t **aircraft, tower_t **tower, int dt_max,
    char *filepath);
#endif