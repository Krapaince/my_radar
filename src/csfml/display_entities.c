/*
** EPITECH PROJECT, 2019
** display_entities.c
** File description:
** function to display netities
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"

void display_aircraft_hitbox(csfml_t *csfml, aircraft_t *aircraft,
sfVector2f *position, sfRectangleShape *rect)
{
    sfColor color[7] = {sfGreen, sfCyan, sfBlue, sfMagenta, {255, 117, 26, 255},
    sfRed, sfWhite};
    sfVector2f size = {aircraft->width, aircraft->height};
    sfColor color_del = {255, 255, 255, 255};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, *position);
    sfRectangleShape_setOutlineColor(rect, color[aircraft->depth]);
    if (aircraft->destroy)
        sfRectangleShape_setOutlineColor(rect, color_del);
    sfRenderWindow_drawRectangleShape(csfml->window, rect, NULL);
}

void display_aircraft(csfml_t *csfml, aircraft_t *aircraft,
sfRectangleShape *rect, sfVector2f *position)
{
    while (aircraft) {
        position->x = aircraft->x0 - aircraft->width / 2;
        position->y = aircraft->y0 - aircraft->height / 2;
        if (2 <= csfml->sprite) {
            sfSprite_setPosition(csfml->s_air, *position);
            sfRenderWindow_drawSprite(csfml->window, csfml->s_air, NULL);
        }
        if ((1 < csfml->hitbox && csfml->hitbox < 5) || csfml->hitbox == 7)
            display_aircraft_hitbox(csfml, aircraft, position, rect);
        aircraft->depth = 5;
        aircraft->qtree_next = NULL;
        aircraft = aircraft->next;
    }
}

void display_tower(csfml_t *csfml, tower_t *tower, sfCircleShape *circle)
{
    sfVector2f position = {0, 0};

    while (tower) {
        if (csfml->sprite == 1 || csfml->sprite == 3) {
            position.x = tower->x - 25;
            position.y = tower->y - 25;
            sfSprite_setPosition(csfml->s_tow, position);
            sfRenderWindow_drawSprite(csfml->window, csfml->s_tow, NULL);
        }
        if (csfml->hitbox < 3 || csfml->hitbox == 7) {
            position.x = tower->x - tower->radius;
            position.y = tower->y - tower->radius;
            sfCircleShape_setPosition(circle, position);
            sfCircleShape_setOutlineThickness(circle, tower->radius * 0.01);
            sfCircleShape_setRadius(circle, tower->radius);
            sfRenderWindow_drawCircleShape(csfml->window, circle, NULL);
        }
        tower = tower->next;
    }
}