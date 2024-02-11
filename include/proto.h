/*
** EPITECH PROJECT, 2018
** proto.h
** File description:
** contain the proto of the of the project
*/

#ifndef PROTO_H_
    #define PROTO_H_
    sfRenderWindow *create_my_window(unsigned int width, unsigned int height);
    sfCircleShape *create_circle(sfVector2f position, float radius);
    circle_t *init_circle_tab(int nb);
    void set_color(smooth_t *s, sfColor *color);
#endif