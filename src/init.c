/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** init the thing
*/

#include "../include/lib.h"
#include "../include/struct.h"

sfRenderWindow *create_my_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "my_radar", 8, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}

sfCircleShape *create_circle(sfVector2f position, float radius)
{
    sfCircleShape *circle = sfCircleShape_create();

    if (circle != NULL) {
        sfCircleShape_setPosition(circle, position);
        sfCircleShape_setRadius(circle, radius);
        sfCircleShape_setOutlineThickness(circle, 1);
        sfCircleShape_setFillColor(circle, sfBlack);
        return (circle);
    }
    else
        return (NULL);
}

sfCircleShape *init_circle(void)
{
    sfVector2f position;
    float radius;

    position.x = 400 + rand() % 500;
    position.y = 200 + rand() % 500;
    radius = rand() % 50;
    return (create_circle(position, radius));
}

circle_t *init_circle_tab(int nb)
{
    circle_t *circle = malloc(sizeof(circle_t) * nb + 1);
    int i = 0;

    if (!circle)
        return (NULL);
    circle[50].c = NULL;
    while (i < nb) {
        circle[i].s = malloc(sizeof(smooth_t));
        if (!circle[i].s)
            return (NULL);
        circle[i].c = init_circle();
        circle[i].s->color.a = 255;
        circle[i].vx = cos(rand()) * 5;
        circle[i].vy = sin(rand()) * 5;
        circle[i].s->active = 1;
        ++i;
    }
    return (circle);
}