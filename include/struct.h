/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** contain the struct defenition
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    typedef struct error
    {
        FILE *script;
        char *buffer;
        size_t n;
        int atot;
        int line;
    } error_t;
    typedef struct aircraft
    {
        float x0;
        float y0;
        float x1;
        float y1;
        float v_x;
        float v_y;
        float delta_time;
        bool x;
        bool y;
        float angle;
        struct aircraft *next;
    } aircraft_t;
    typedef struct tower
    {
        int x;
        int y;
        int radius;
        struct tower *next;
    } tower_t;
#endif