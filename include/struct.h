/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** contain the struct defenition
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    typedef struct
    {
        int active;
        int padding;
        int sign;
        int value_to_put;
        sfUint8 res;
        sfColor color;
        sfUint8 *color_choice;
    } smooth_t;
    typedef struct
    {
        sfCircleShape *c;
        int vx;
        int vy;
        smooth_t *s;
    } circle_t;
#endif