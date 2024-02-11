/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** launch the render of the entities
*/

#include "lib.h"
#include "struct.h"
#include "csfml.h"
#include "quadtree.h"

void display_aircraft(csfml_t *csfml, aircraft_t *aircraft,
sfRectangleShape *rect, sfVector2f *position)
{
    sfVector2f size = {0, 0};

    while (aircraft) {
        position->x = aircraft->x0 - aircraft->width / 2;
        position->y = aircraft->y0 - aircraft->height / 2;
        if (2 <= csfml->sprite) {
            sfSprite_setPosition(csfml->s_air, *position);
            sfSprite_setRotation(csfml->s_air, aircraft->angle);
            sfRenderWindow_drawSprite(csfml->window, csfml->s_air, NULL);
        }
        if ((1 < csfml->hitbox && csfml->hitbox < 5) || csfml->hitbox == 7) {
            size.x = aircraft->width;
            size.y = aircraft->height;
            sfRectangleShape_setSize(rect, size);
            sfRectangleShape_setPosition(rect, *position);
            sfRectangleShape_setRotation(rect, aircraft->angle);
            sfRenderWindow_drawRectangleShape(csfml->window, rect, NULL);
        }
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

void qtree_display(csfml_t *csfml, qtree_t *tree,
sfRectangleShape *rect, sfVector2f *position)
{
    sfVector2f size = {tree->width, tree->height};
    int i = 0;

    if (csfml->hitbox == 2 || csfml->hitbox == 3 || csfml->hitbox == 6)
        return;
    if (tree->divided) {
        while (i < 4) {
            qtree_display(csfml, tree->child[i], rect, position);
            ++i;
        }
    }
    position->x = tree->x;
    position->y = tree->y;
    sfRectangleShape_setPosition(rect, *position);
    sfRectangleShape_setSize(rect, size);
    sfRenderWindow_drawRectangleShape(csfml->window, rect, NULL);
}

bool create_hitbox_shape(sfRectangleShape **rect, sfCircleShape **circle)
{
    *rect = sfRectangleShape_create();
    *circle = sfCircleShape_create();
    if (!*rect || !*circle)
        return (false);
    sfCircleShape_setOutlineColor(*circle, sfRed);
    sfCircleShape_setFillColor(*circle, sfTransparent);
    sfRectangleShape_setFillColor(*rect, sfTransparent);
    sfRectangleShape_setOutlineColor(*rect, sfRed);
    sfRectangleShape_setOutlineThickness(*rect, 1);
    return (true);
}

bool display(csfml_t *csfml, aircraft_t *aircraft, tower_t *tower,
qtree_t *tree)
{
    sfRectangleShape *rect = NULL;
    sfCircleShape *circle = NULL;
    sfVector2f position = {0, 0};

    sfRenderWindow_drawSprite(csfml->window, csfml->s_back, NULL);
    if (!create_hitbox_shape(&rect, &circle))
        return (false);
    qtree_display(csfml, tree, rect, &position);
    display_tower(csfml, tower, circle);
    display_aircraft(csfml, aircraft, rect, &position);
    if (!time_update(csfml))
        return (false);
    sfRenderWindow_display(csfml->window);
    sfCircleShape_destroy(circle);
    sfRectangleShape_destroy(rect);
    return (true);
}