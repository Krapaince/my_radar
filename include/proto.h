/*
** EPITECH PROJECT, 2018
** proto.h
** File description:
** contain the proto of the of the project
*/

#ifndef PROTO_H_
    #define PROTO_H_
    int traffic_simulation(char *filepath);
    int launch_simulation(aircraft_t **aircraft, tower_t **tower);
    int load(aircraft_t **plane, tower_t **tower, int dt, char *filepath);
    int error_script(char *filepath);
    void destroy_tower(tower_t *tower);
    void destroy_aircraft(aircraft_t *aircraft);
    void destroy(aircraft_t *aircraft, tower_t *tower);
#endif